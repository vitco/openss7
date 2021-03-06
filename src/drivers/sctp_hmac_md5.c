/*****************************************************************************

 @(#) File: src/drivers/sctp_hmac_md5.c

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2015  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software: you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation, version 3 of the license.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
 details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>, or
 write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
 02139, USA.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 *****************************************************************************/

static char const ident[] = "src/drivers/sctp_hmac_md5.c (" PACKAGE_ENVR ") " PACKAGE_DATE;

#undef _DEBUG
#undef SCTP_CONFIG_DEBUG

#ifdef NEED_LINUX_AUTOCONF_H
#include NEED_LINUX_AUTOCONF_H
#endif
#include <linux/version.h>
#include <linux/compiler.h>
#include <linux/types.h>
#include <linux/string.h>

#include "sctp_md5.h"
#include "sctp_hmac_md5.h"

/* 
 *  -------------------------------------------------------------------------
 *
 *  HMAC-MD5
 *
 *  -------------------------------------------------------------------------
 *
 *  Code adapted directly from RFC 2104.
 */
void
hmac_md5(uint8_t *text, int tlen, uint8_t *key, int klen, uint8_t *digest)
{
	MD5_CTX context;
	uint8_t k_ipad[65];
	uint8_t k_opad[65];
	uint8_t tk[16];
	int i;

	if (klen > 64) {
		MD5_CTX ctx;

		MD5Init(&ctx);
		MD5Update(&ctx, key, klen);
		MD5Final(tk, &ctx);
		key = tk;
		klen = 16;
	}
	memset(k_ipad, 0, sizeof(k_ipad));
	memset(k_opad, 0, sizeof(k_opad));
	memcpy(k_ipad, key, klen);
	memcpy(k_opad, key, klen);
	for (i = 0; i < 64; i++) {
		k_ipad[i] ^= 0x36;
		k_opad[i] ^= 0x5c;
	}
	/* inner */
	MD5Init(&context);
	MD5Update(&context, k_ipad, 64);
	MD5Update(&context, text, tlen);
	MD5Final(digest, &context);
	/* outer */
	MD5Init(&context);
	MD5Update(&context, k_opad, 64);
	MD5Update(&context, digest, 16);
	MD5Final(digest, &context);
}
