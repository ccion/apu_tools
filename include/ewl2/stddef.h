/* EWL
 * Copyright © 1995-2009 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2009/05/14 16:55:27 $
 * $Revision: 1.1 $
 */

#ifndef _EWL_STDDEF_H
#define _EWL_STDDEF_H

#include <ansi_parms.h>

#if !_EWL_USING_CW_C_HEADERS_
	#error You must have the non-EWL C header file access path before the EWL access path
#else

#include <cstddef>

#if defined(__cplusplus) && defined(_EWL_USING_NAMESPACE)
	using std::ptrdiff_t;
	using std::size_t;
#endif /* defined(__cplusplus) && defined(_EWL_USING_NAMESPACE) */

#endif /* _EWL_USING_CW_C_HEADERS_ */

#endif /* _EWL_STDDEF_H */
