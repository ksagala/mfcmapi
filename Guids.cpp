#include "stdafx.h"

#define INITGUID
#define USES_IID_IMsgStore
#define USES_IID_IMAPIProgress
#define USES_IID_IMAPIAdviseSink
#define USES_IID_IMAPIMessageSite
#define USES_IID_IMAPIViewContext
#define USES_IID_IMAPIViewAdviseSink
#define USES_IID_IMAPITable
#define USES_IID_IMAPIFolder
#define USES_IID_IMAPIContainer
#define USES_IID_IMAPIForm
#define USES_IID_IMAPIProp
#define USES_IID_IPersistMessage
#define USES_IID_IMessage
#define USES_IID_IAttachment
#define USES_IID_IUnknown
#define USES_IID_IABContainer
#define USES_IID_IDistList
#define USES_IID_IStreamDocfile
#define USES_PS_MAPI
#define USES_PS_PUBLIC_STRINGS
#define USES_PS_ROUTING_EMAIL_ADDRESSES
#define USES_PS_ROUTING_ADDRTYPE
#define USES_PS_ROUTING_DISPLAY_NAME
#define USES_PS_ROUTING_ENTRYID
#define USES_PS_ROUTING_SEARCH_KEY
#define USES_MUID_PROFILE_INSTANCE
#define USES_IID_IMAPIClientShutdown
#define USES_IID_IMAPIProviderShutdown
#define USES_IID_IMsgServiceAdmin2
#define USES_IID_IMessageRaw

#include <initguid.h>
#include <MAPIguid.h>
#include <mapiaux.h>

#ifdef EDKGUID_INCLUDED
#undef EDKGUID_INCLUDED
#endif
#include <EDKGUID.H>

#include "guids.h"