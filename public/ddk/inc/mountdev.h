/*++

Copyright (c) Microsoft Corporation. All rights reserved.

You may only use this code if you agree to the terms of the Windows Research Kernel Source Code License agreement (see License.txt).
If you do not agree to the terms, do not use the code.


Module Name:

    mountdev.h

Abstract:

    This file defines the private interfaces between the mount point manager
    and the mounted devices.

--*/

#ifndef _MOUNTDEV_
#define _MOUNTDEV_

#include <mountmgr.h>

#define IOCTL_MOUNTDEV_QUERY_UNIQUE_ID              CTL_CODE(MOUNTDEVCONTROLTYPE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY      CTL_CODE(MOUNTDEVCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTDEV_QUERY_SUGGESTED_LINK_NAME    CTL_CODE(MOUNTDEVCONTROLTYPE, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MOUNTDEV_LINK_CREATED                 CTL_CODE(MOUNTDEVCONTROLTYPE, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTDEV_LINK_DELETED                 CTL_CODE(MOUNTDEVCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTDEV_QUERY_STABLE_GUID            CTL_CODE(MOUNTDEVCONTROLTYPE, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)

//
// Output structure for IOCTL_MOUNTDEV_QUERY_UNIQUE_ID.
// Input structure for IOCTL_MOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY.
//

typedef struct _MOUNTDEV_UNIQUE_ID {
    USHORT  UniqueIdLength;
    UCHAR   UniqueId[1];
} MOUNTDEV_UNIQUE_ID, *PMOUNTDEV_UNIQUE_ID;

//
// Output structure for IOCTL_MOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY.
//

typedef struct _MOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY_OUTPUT {
    ULONG   Size;
    USHORT  OldUniqueIdOffset;
    USHORT  OldUniqueIdLength;
    USHORT  NewUniqueIdOffset;
    USHORT  NewUniqueIdLength;
} MOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY_OUTPUT, *PMOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY_OUTPUT;

//
// MOUNTDEV_NAME
//
// Input structure for IOCTL_MOUNTDEV_LINK_CREATED.
// Input structure for IOCTL_MOUNTDEV_LINK_DELETED.
//

//
// Output structure for IOCTL_MOUNTDEV_QUERY_SUGGESTED_LINK_NAME
//

typedef struct _MOUNTDEV_SUGGESTED_LINK_NAME {
    BOOLEAN UseOnlyIfThereAreNoOtherLinks;
    USHORT  NameLength;
    WCHAR   Name[1];
} MOUNTDEV_SUGGESTED_LINK_NAME, *PMOUNTDEV_SUGGESTED_LINK_NAME;

//
// Output structure for IOCTL_MOUNTDEV_QUERY_STABLE_GUID.
//

typedef struct _MOUNTDEV_STABLE_GUID {
    GUID    StableGuid;
} MOUNTDEV_STABLE_GUID, *PMOUNTDEV_STABLE_GUID;

#endif

