/*
 * Dispatcher.java Version-1.4, 2002/11/22 09:26:10 -0800 (Fri)
 * ECTF S.410-R2 Source code distribution.
 *
 * Copyright (c) 2002, Enterprise Computer Telephony Forum (ECTF),
 * All Rights Reserved.
 *
 * Use and redistribution of this file is subject to a License.
 * For terms and conditions see: javax/telephony/media/LICENSE.HTML
 * 
 * In short, you can use this source code if you keep and display
 * the ECTF Copyright and the License conditions. The code is supplied
 * "AS IS" and ECTF disclaims all warranties and liability.
 */

package javax.telephony.media.provider;	

import java.util.Enumeration;
import java.util.Vector;
import java.util.EventListener;

/**
 * Provides a framework for managing Listeners,
 * and building event queues and dispatch threads.
 * <p>
 * Dispatcher delivers an DispatchableEvent to a all Listeners.
 * The DispatchableEvent decides which method to invoke on 
 * which Listeners.
 * <p>
 * The Dispatcher handles any Exceptions generated by
 * Event dispatching or by the Listeners.
 * <p>
 * This Dispatcher is very generic, the actual knowledge
 * of which Listener class and which method to invoke
 * is encapsulated in the Events that implement DispatchableEvent. 
 * <p>
 * This class can be extended by implementing: getNextEvent()
 * and providing whatever constructor or initializers are necessary.
 * <p>
 * An event can be dispatched from any thread that calls
 * <tt>notiftyListeners()</tt>.
 * The supplied Thread.run() method calls notifyListeners,
 * but this class must be specialized to supply a <tt>getNextEvent()</tt>
 * method.
 *
 * @author  Jeff Peck
 * @since   JTAPI-1.4
 */
public 
class Dispatcher implements Runnable {
    /** Supplies a method to dispatch an object to its Listener.
     * Typically, some specialization of EventObject implements this interface.
     * <p>
     * <b>Implementation Note:</b>
     * The <tt>dispatch</tt> method verifies the supplied listener 
     * is suitable for this event then casts the listener and 
     * invokes the appropriate callback:
     * <pre>
     * if (listener instanceof MyListener) 
     *    ((MyListener)listener).MyCallback(this);
     * </pre>
     */
    public interface DispatchableEvent {
	void dispatch(EventListener listener);
     }

    /** Supplies a method to handle Exceptions generated while dispatching.*/
    public interface ExceptionHandler {
	/**
	 * Callback from the Dispatcher if there is an exception
	 * while dispatching event to a Listener.
	 * <p>
	 * Typically, this prints the Exception. 
	 * and may invoke dispatcher.stop().
	 * @param dispatcher the Dispatcher instance
	 * @param exception the Exception thrown while processing the Event
	 * @param listener the EventListener when the Exception occured
	 * @param event the DispatchableEvent when the Exception occured
	 */
	void onDispatcherException(Dispatcher dispatcher, 
				   Exception exception, 
				   EventListener listener, 
				   DispatchableEvent event);
    }    

    private ExceptionHandler handler = null;

    /**
     * Set a Handler for Exception handling. 
     * The default implementation of <tt>Dispatcher.onDispatcherException</tt>
     * invokes <tt>handler.onDispatcherException</tt>.
     * <p>
     * Therefore, there are two ways to override what happens
     * when there is an Exception during dispatch:
     * <ol><li>
     * <tt>setExceptionHandler()</tt> on an existing base Dispatcher,
     * providing an object that implements onDispatcherException().
     * </li><li>
     * Craete a specialized Dispatcher class that overrides
     * an provides its own implementaiton of onDispatcherException().
     * </li></ol>
     * <p>
     * @param handler a Dispatcher.ExceptionHandler or <tt>null</tt>
     * to revert to the default behavior: print and stop.
     */
    public void setExceptionHandler(ExceptionHandler handler) {
	this.handler = handler;
    }

    /** 
     * Default handler for Exception during dispatch.
     * Invokes onDisptacherHandler on the Dispatcher.ExceptionHandler
     * identified by Dispatcher.setExceptionHandler(ExceptionHandler).
     * The default ExceptionHandler prints the Exception
     * and stops this Dispatcher.
     * <p>
     * This behavior may be overridden by subclassing Dispatcher
     * to change this method; or just supply another ExceptionHandler
     * using setExceptionHandler(ExceptionHandler).
     * @see ExceptionHandler
     */
    protected void onDispatcherException(Dispatcher disp,
					 Exception ex, 
					 EventListener listener,
					 DispatchableEvent event)
    {
	if (handler != null) try {
	    handler.onDispatcherException(disp, ex, listener, event);
	} catch (Exception ex2) {
	    System.err.println ("!Exception in Handler! "+handler+": "+ex2);
	    ex2.printStackTrace(System.err);
	    printDispatcherException("Dispatcher: ", disp, ex, listener, event);
	} else {
	    printDispatcherException("Dispatcher: ", disp, ex, listener, event);
	}
    }

    /** Print the Exception and other information */
    public static void printDispatcherException(java.lang.String label, 
						Dispatcher disp,
						Exception ex, 
						EventListener listener,
						DispatchableEvent event)
    {
	System.err.println(label+ disp);
	System.err.println(label+"Exception = "+ex);
	System.err.println(label+"Listener = "+listener);
	System.err.println(label+"Event = "+event);
	ex.printStackTrace(System.err);
    }

    private static final class VectorX extends Vector {
	/** Extract Vector to an java.lang.Object[].
	 * like JDK-1.2 Vector.toArray(), but works in Java-1
	 */
	public java.lang.Object[] toArray(java.lang.Object[] a) {
	    if (a.length < elementCount)
		a = new java.lang.Object[elementCount];
	    System.arraycopy(elementData, 0, a, 0, elementCount);
	    return a;
	}
    }

    private VectorX theListeners = new VectorX();

    /** Add the given listener to the list.
     * If listener already on the list, this has no effect.
     * @param listener an EventListener object.
     */
    public void addListener( EventListener listener ) {
	synchronized (theListeners) {
	    if (!theListeners.contains(listener))
		theListeners.addElement(listener);
	    // System.out.println("Add: "+this);
	    // Exception e = new Exception("StackDump:");
	    // e.printStackTrace();
	}
    }

    /** Remove the given listener from the list.
     * If listener is not on the list, this has no effect.
     * @param listener an EventListener object.
     */
    public void removeListener( EventListener listener ) {
	synchronized (theListeners) {
	    theListeners.removeElement(listener);
	    // System.out.println("Remove: "+this);
	    // Exception e = new Exception("StackDump:");
	    // e.printStackTrace();
	}
    }

    /**
     * Causes the given DispatchableEvent to be delivered
     * to the Listeners that are expecting it.
     * <p>
     * All Listeners are considered, those that implement the
     * Listener interface used by the event are invoked.
     * <p>
     * This method can be called directly, or if events are being
     * queued, then the Dispatcher Thread's <tt>run()</tt> method
     * will call then when an event is available from <tt>getNextEvent().</tt>
     */
    //protected 
    public void notifyListeners(DispatchableEvent event) {
	// addListener and removeListener blocked while we
	// compute the current listeners.
	synchronized (theListeners) {
	    int nListeners = theListeners.size();
	    // need to avoid altering theListeners if using Enumeration:
	    notifyArray = theListeners.toArray(notifyArray);

	    EventListener listener = null;
	    //System.out.println("Notify: "+this);
	    //System.out.println("notifyListeners: "+event);
	    for (int i = 0; i < nListeners; i++) {
		if (stopNow) return;
		listener = (EventListener)notifyArray[i];
		try {
		    event.dispatch(listener); // user code, may add/remove Listeners
		} catch (Exception ex) {
		    onDispatcherException(this, ex, listener, event);
		}
	    }
	}
    }

    /** snapshot of theListeners, so notifyListeners is not effected
     * if some Listener attempts to add/remove a Listener.
     * [which is not restricted by locking 'theListeners']
     * <br><b>Note:</b>this is reallocated only if it gets bigger.
     */
    private java.lang.Object[] notifyArray = new java.lang.Object[2];

    public java.lang.String toString() {
	return super.toString() + " {"+
	    "\n\t"+"state = "+state+" stopNow = "+stopNow +
	    "\n\t"+"thread = " + dispatcherThread +
	    "\n\t"+"theListeners = " + theListeners +
	    "}";
    }

    /** To be "Runnable", a subclass must re-define this method. */
    protected DispatchableEvent getNextEvent() throws Exception {
	stopNow = true;
	throw new RuntimeException("Dispatcher.getNextEvent() is not defined.");
    }

    // *************************************************************
    // **** above is the generic Listener/Notify stuff 
    // ****
    // **** below is the Runnable Thread to invoke getNextEvent()
    // *************************************************************/

    /** get a DispatchableEvent and dispatch it to all EventListeners
     * until stop().
     */
    public void run() {
	state = stateRunning;
	while (!stopNow) {
	    DispatchableEvent event = null;
	    try {
		event = getNextEvent();	// Note: if (stopNow) then (event == null) 
	    } catch (Exception ex) {
		onDispatcherException(this, ex, null, null);
	    }
	    if(stopNow) break;
	    notifyListeners(event);
	}
	state = stateDone;
	//System.out.println("Dispather exiting: "+this);
    }

    /** if true, stop Dispatch Thread ASAP. */
    protected boolean stopNow = false;
    protected java.lang.String state = stateNew;
    final static java.lang.String stateNew 	= "New"; 	// stopNow=F
    final static java.lang.String stateStart 	= "Start"; 	// stopNow=F
    final static java.lang.String stateRunning	= "Running";	// stopNow=F/stopNow=T
    final static java.lang.String stateStop	= "Stop";	// Running + stopNow=T
    final static java.lang.String stateDone	= "Done";	// run done, stopNow=T
    final static java.lang.String stateClosed 	= "Closed";	// close done,stopNow=T
    
    private static final java.lang.String threadNamePrefix = "DT-";
    private static int dispatcherNumber = 1;
    private static synchronized java.lang.String newName() {
	// if (dispatcherNumber <= 0) {dispatcherNumber=1; threadNamePrefix+="x";}
	return threadNamePrefix+(dispatcherNumber++)+"-";
    }

    /** the Thread that runs Listener callback methods. */
    protected Thread dispatcherThread = null;

    public boolean isRunning() {
	return (dispatcherThread != null) && (dispatcherThread.isAlive());
    }

    /** a diagnostic routine */
    static void stacktrace(java.io.PrintStream strm, java.lang.String str) {
	strm.println(str);
	new Exception("stacktrace").printStackTrace(strm);
	strm.println("currentThread()="+Thread.currentThread());
    }

    /** A utility routine to get short name for an object.
     * Used to set default name of Dispatcher Thread.
     */
    static public java.lang.String objName(java.lang.Object obj) {
	java.lang.String name = obj.getClass().getName();
	name = name.substring(name.lastIndexOf(".")+1);
	name += "@"+Integer.toString(System.identityHashCode(obj),16);
	return name;
    }

    public void start() {
	start(objName(this));
    }
    public void start(java.lang.Object obj) {
	start(objName(this)+((obj == null) ? "" : "-"+objName(obj)));
    }
    /** start a Thread for this Dispatcher. */
    synchronized
    public void start(java.lang.String name) {
	java.lang.String newname = newName()+name;
	if (isRunning()) {
	    dispatcherThread.setName(newname);
	    return;
	}
	state = stateStart;
	stopNow = false;

	// stacktrace(System.out, "Dispatcher.start: "+newname);
	dispatcherThread = new Thread(this, newname);
	dispatcherThread.setDaemon(true);
	dispatcherThread.start();
    }

    /** 
     * Stop the Thread for this Dispatcher. 
     * Sets field stopNow, and interrupts the thread.
     * <p>
     * If you need access to the Thread, specialize the class.
     */
    synchronized
    public void stop() {
	// stacktrace(System.out, "Dispatcher.stop: "+dispatcherThread);
	stopNow = true;
	state = stateStop;
	if (isRunning() && (Thread.currentThread() != dispatcherThread)) {
	    dispatcherThread.interrupt(); // kick it so it will check stopNow
	}
    }

    /** stop Dispatcher, return to initial state. 
     * nullify various pointers to deconstruct this Dispatcher.
     */
    synchronized
    public void close() {
	stop();
	dispatcherThread = null;
	theListeners = null;
	handler = null;
	state = stateClosed;
    }
}