#ifndef __LOCAL_MTPOMMIB_H__
#define __LOCAL_MTPOMMIB_H__

/*
 * This file was generated by mib2c and is intended for use as a mib module
 * for the ucd-snmp snmpd agent.
 */

/* our storage structure(s) */

struct mtpOmMIB_data {
	unsigned int mtpOmMIB_request;

};

struct mtpOmHandledMSUsOpcDpcSioTable_data {
	unsigned int mtpOmHandledMSUsOpcDpcSioTable_request;

	char *mtpOmSio;
	size_t mtpOmSioLen;
	long mtpOmHandledMSUsOpcDpcSio;
	long mtpOmHandledMSUsOpcDpcSioRowStatus;
};

struct mtpOmHandledOctetsOpcDpcSioTable_data {
	unsigned int mtpOmHandledOctetsOpcDpcSioTable_request;

	char *mtpOmSio;
	size_t mtpOmSioLen;
	long mtpOmHandledOctetsOpcDpcSioInterval;
	long mtpOmHandledOctetsOpcDpcSio;
	long mtpOmHandledOctetsOpcDpcSioRowStatus;
};

struct mtpOmHandledOctetsSIOTable_data {
	unsigned int mtpOmHandledOctetsSIOTable_request;
	char *mtpOmSio;
	size_t mtpOmSioLen;
	long mtpOmHandledOctetsSIO;
};

struct mtpOmOblSpUtilizationTable_data {
	unsigned int mtpOmOblSpUtilizationTable_request;
	long mtpOmAdjacentInaccessibleDuration;
};

struct mtpOmAllSpUtilizationTable_data {
	unsigned int mtpOmAllSpUtilizationTable_request;
	long mtpOmAdjacentInaccessibleEvents;
	long mtpOmAllSpUtilizationRowStatus;
};

struct mtpOmReceivedOctetsOPCTable_data {
	unsigned int mtpOmReceivedOctetsOPCTable_request;

	long mtpOmReceivedOctetsOPCInterval;
	long mtpOmReceivedOctetsOPC;
	long mtpOmReceivedOctetsOPCRowStatus;
};

struct mtpOmReceivedOctetsOpcSioTable_data {
	unsigned int mtpOmReceivedOctetsOpcSioTable_request;

	char *mtpOmSio;
	size_t mtpOmSioLen;
	long mtpOmReceivedOctetsOpcSioInterval;
	long mtpOmReceivedOctetsOpcSio;
	long mtpOmReceivedOctetsOpcSioRowStatus;
};

struct mtpOmSpDataTable_data {
	unsigned int mtpOmSpDataTable_request;

	long mtpOmSpDiscardedMSUs;
	long mtpOmSpTransmittedUPUnavailable;
	long mtpOmSpReceivedUPUnavailable;
	long mtpOmSpReceivedTFC;
	long mtpOmSpReceivedTFCLevel0;
	long mtpOmSpReceivedTFCLevel1;
	long mtpOmSpReceivedTFCLevel2;
	long mtpOmSpReceivedTFCLevel3;
};

struct mtpOmTransmittedOctetsDPCTable_data {
	unsigned int mtpOmTransmittedOctetsDPCTable_request;

	long mtpOmTransmittedOctetsDPCRowStatus;
};

struct mtpOmTransmittedOctetsDPCTable_data {
	unsigned int mtpOmTransmittedOctetsDPCTable_request;

	long mtpOmTransmittedOctetsDPCRowStatus;
};

struct mtpOmTransmittedOctetsDPCTable_data {
	unsigned int mtpOmTransmittedOctetsDPCTable_request;

	long mtpOmTransmittedOctetsDPCRowStatus;
};

struct mtpOmTransmittedOctetsDpcSioTable_data {
	unsigned int mtpOmTransmittedOctetsDpcSioTable_request;

	char *mtpOmSio;
	size_t mtpOmSioLen;
	long mtpOmTransmittedOctetsDpcSio;
	long mtpOmTransmittedOctetsDpcSioRowStatus;
};

struct mtpOmSignRsInformationTable_data {
	unsigned int mtpOmSignRsInformationTable_request;
	long mtpOmRouteSetUnavailable;
	long mtpOmRouteSetUnavailableDuration;
};

struct mtpOmSlsDurationTable_data {
	unsigned int mtpOmSlsDurationTable_request;
	long mtpOmSlsUnavailable;
};

struct mtpOmAll5And30MinSlDurationTable_data {
	unsigned int mtpOmAll5And30MinSlDurationTable_request;
	long mtpOmAll5And30MinSlDurationInterval;
	long mtpOmLocalMgntInhibit;
	long mtpOmLocalMgntUninhibit;
	long mtpOmLocalBusy;
	long mtpOmAll5And30MinSlDurationRowStatus;
};

struct mtpOmOblSlDurationTable_data {
	unsigned int mtpOmOblSlDurationTable_request;
	long mtpOmSlUnavailabilityDuration;
	long mtpOmSlInServiceDuration;
};

struct mtpOmAll30MinSlDurationTable_data {
	unsigned int mtpOmAll30MinSlDurationTable_request;
	long mtpOmAll30MinSlDurationInterval;
	long mtpOmSlLocalInhibition;
	long mtpOmSlRemoteInhibition;
	long mtpOmSlFailed;
	long mtpOmSlRemoteProcOutage;
	long mtpOmAll30MinSlDurationRowStatus;
};

struct mtpOmOblSlUtilizationTable_data {
	unsigned int mtpOmOblSlUtilizationTable_request;
	long mtpOmSlSignUnitsReceived;
	long mtpOmSlTransmittedOctetsSIFSIO;
	long mtpOmSlReceivedOctetsSIFSIO;
	long mtpOmSlDiscardedMSUs;
};

struct mtpOmAllSlUtilizationTable_data {
	unsigned int mtpOmAllSlUtilizationTable_request;
	long mtpOmSlAlignment;
	long mtpOmSlNegAckReceived;
	long mtpOmSlRetransmittedOctets;
	long mtpOmSlTransmittedMSUs;
	long mtpOmSlReceivedMSUs;
	long mtpOmAllSlUtilizationRowStatus;
};

struct mtpOmSlCongestionTable_data {
	unsigned int mtpOmSlCongestionTable_request;

	long mtpOmSlCongestionFirst;
	long mtpOmSlCongestionInterval;
	long mtpOmSlCongestionStarts;
	long mtpOmSlCongestionStops;
	long mtpOmSlCongestionEventsMSULoss;
	long mtpOmSlCongestionRowStatus;
};

/* enum definitions from the covered mib sections */

#define MTPOMSLCONGESTIONFIRST_TRUE              1
#define MTPOMSLCONGESTIONFIRST_FALSE             2

/* function prototypes */

void init_mtpOmMIB(void);
void deinit_mtpOmMIB(void);
int term_mtpOmMIB(int majorID, int minorID, void *serverarg, void *clientarg);

FindVarMethod var_mtpOmMIB;
void parse_mtpOmMIB(const char *, char *);
SNMPCallback store_mtpOmMIB;
void refresh_mtpOmMIB(void);

FindVarMethod var_mtpOmHandledMSUsOpcDpcSioTable;
void parse_mtpOmHandledMSUsOpcDpcSioTable(const char *, char *);
SNMPCallback store_mtpOmHandledMSUsOpcDpcSioTable;
void refresh_mtpOmHandledMSUsOpcDpcSioTable(void);
FindVarMethod var_mtpOmHandledOctetsOpcDpcSioTable;
void parse_mtpOmHandledOctetsOpcDpcSioTable(const char *, char *);
SNMPCallback store_mtpOmHandledOctetsOpcDpcSioTable;
void refresh_mtpOmHandledOctetsOpcDpcSioTable(void);
FindVarMethod var_mtpOmHandledOctetsSIOTable;
void parse_mtpOmHandledOctetsSIOTable(const char *, char *);
SNMPCallback store_mtpOmHandledOctetsSIOTable;
void refresh_mtpOmHandledOctetsSIOTable(void);
FindVarMethod var_mtpOmOblSpUtilizationTable;
void parse_mtpOmOblSpUtilizationTable(const char *, char *);
SNMPCallback store_mtpOmOblSpUtilizationTable;
void refresh_mtpOmOblSpUtilizationTable(void);
FindVarMethod var_mtpOmAllSpUtilizationTable;
void parse_mtpOmAllSpUtilizationTable(const char *, char *);
SNMPCallback store_mtpOmAllSpUtilizationTable;
void refresh_mtpOmAllSpUtilizationTable(void);
FindVarMethod var_mtpOmReceivedOctetsOPCTable;
void parse_mtpOmReceivedOctetsOPCTable(const char *, char *);
SNMPCallback store_mtpOmReceivedOctetsOPCTable;
void refresh_mtpOmReceivedOctetsOPCTable(void);
FindVarMethod var_mtpOmReceivedOctetsOpcSioTable;
void parse_mtpOmReceivedOctetsOpcSioTable(const char *, char *);
SNMPCallback store_mtpOmReceivedOctetsOpcSioTable;
void refresh_mtpOmReceivedOctetsOpcSioTable(void);
FindVarMethod var_mtpOmSpDataTable;
void parse_mtpOmSpDataTable(const char *, char *);
SNMPCallback store_mtpOmSpDataTable;
void refresh_mtpOmSpDataTable(void);
FindVarMethod var_mtpOmTransmittedOctetsDPCTable;
void parse_mtpOmTransmittedOctetsDPCTable(const char *, char *);
SNMPCallback store_mtpOmTransmittedOctetsDPCTable;
void refresh_mtpOmTransmittedOctetsDPCTable(void);
FindVarMethod var_mtpOmTransmittedOctetsDPCTable;
void parse_mtpOmTransmittedOctetsDPCTable(const char *, char *);
SNMPCallback store_mtpOmTransmittedOctetsDPCTable;
void refresh_mtpOmTransmittedOctetsDPCTable(void);
FindVarMethod var_mtpOmTransmittedOctetsDPCTable;
void parse_mtpOmTransmittedOctetsDPCTable(const char *, char *);
SNMPCallback store_mtpOmTransmittedOctetsDPCTable;
void refresh_mtpOmTransmittedOctetsDPCTable(void);
FindVarMethod var_mtpOmTransmittedOctetsDpcSioTable;
void parse_mtpOmTransmittedOctetsDpcSioTable(const char *, char *);
SNMPCallback store_mtpOmTransmittedOctetsDpcSioTable;
void refresh_mtpOmTransmittedOctetsDpcSioTable(void);
FindVarMethod var_mtpOmSignRsInformationTable;
void parse_mtpOmSignRsInformationTable(const char *, char *);
SNMPCallback store_mtpOmSignRsInformationTable;
void refresh_mtpOmSignRsInformationTable(void);
FindVarMethod var_mtpOmSlsDurationTable;
void parse_mtpOmSlsDurationTable(const char *, char *);
SNMPCallback store_mtpOmSlsDurationTable;
void refresh_mtpOmSlsDurationTable(void);
FindVarMethod var_mtpOmAll5And30MinSlDurationTable;
void parse_mtpOmAll5And30MinSlDurationTable(const char *, char *);
SNMPCallback store_mtpOmAll5And30MinSlDurationTable;
void refresh_mtpOmAll5And30MinSlDurationTable(void);
FindVarMethod var_mtpOmOblSlDurationTable;
void parse_mtpOmOblSlDurationTable(const char *, char *);
SNMPCallback store_mtpOmOblSlDurationTable;
void refresh_mtpOmOblSlDurationTable(void);
FindVarMethod var_mtpOmAll30MinSlDurationTable;
void parse_mtpOmAll30MinSlDurationTable(const char *, char *);
SNMPCallback store_mtpOmAll30MinSlDurationTable;
void refresh_mtpOmAll30MinSlDurationTable(void);
FindVarMethod var_mtpOmOblSlUtilizationTable;
void parse_mtpOmOblSlUtilizationTable(const char *, char *);
SNMPCallback store_mtpOmOblSlUtilizationTable;
void refresh_mtpOmOblSlUtilizationTable(void);
FindVarMethod var_mtpOmAllSlUtilizationTable;
void parse_mtpOmAllSlUtilizationTable(const char *, char *);
SNMPCallback store_mtpOmAllSlUtilizationTable;
void refresh_mtpOmAllSlUtilizationTable(void);
FindVarMethod var_mtpOmSlCongestionTable;
void parse_mtpOmSlCongestionTable(const char *, char *);
SNMPCallback store_mtpOmSlCongestionTable;
void refresh_mtpOmSlCongestionTable(void);

WriteMethod write_mtpOmHandledMSUsOpcDpcSioRowStatus;
WriteMethod write_mtpOmHandledOctetsOpcDpcSioInterval;
WriteMethod write_mtpOmHandledOctetsOpcDpcSioRowStatus;
WriteMethod write_mtpOmAllSpUtilizationRowStatus;
WriteMethod write_mtpOmReceivedOctetsOPCInterval;
WriteMethod write_mtpOmReceivedOctetsOPCRowStatus;
WriteMethod write_mtpOmReceivedOctetsOpcSioInterval;
WriteMethod write_mtpOmReceivedOctetsOpcSioRowStatus;
WriteMethod write_mtpOmTransmittedOctetsDpcSioRowStatus;
WriteMethod write_mtpOmAll5And30MinSlDurationInterval;
WriteMethod write_mtpOmAll5And30MinSlDurationRowStatus;
WriteMethod write_mtpOmAll30MinSlDurationInterval;
WriteMethod write_mtpOmAll30MinSlDurationRowStatus;
WriteMethod write_mtpOmAllSlUtilizationRowStatus;
WriteMethod write_mtpOmSlCongestionFirst;
WriteMethod write_mtpOmSlCongestionInterval;
WriteMethod write_mtpOmSlCongestionRowStatus;

#endif				/* __LOCAL_MTPOMMIB_H__ */
