name    snmpapi
type    win32
init    SNMPAPI_DllMain

import ntdll.dll

debug_channels (snmpapi)

@ stub SnmpSvcAddrIsIpx
@ stub SnmpSvcAddrToSocket
@ stub SnmpSvcBufRevAndCpy
@ stub SnmpSvcBufRevInPlace
@ stub SnmpSvcDecodeMessage
@ stub SnmpSvcEncodeMessage
@ stub SnmpSvcGenerateAuthFailTrap
@ stub SnmpSvcGenerateColdStartTrap
@ stub SnmpSvcGenerateLinkDownTrap
@ stub SnmpSvcGenerateLinkUpTrap
@ stub SnmpSvcGenerateTrap
@ stub SnmpSvcGenerateWarmStartTrap
@ stub SnmpSvcGetEnterpriseOID
@ stub SnmpSvcGetUptime
@ stub SnmpSvcInitUptime
@ stub SnmpSvcReleaseMessage
@ stub SnmpSvcReportEvent
@ stub SnmpSvcSetLogLevel
@ stub SnmpSvcSetLogType
@ stub SnmpUtilAnsiToUnicode
@ stub SnmpUtilDbgPrint
@ stub SnmpUtilIdsToA
@ stub SnmpUtilMemAlloc
@ stub SnmpUtilMemFree
@ stub SnmpUtilMemReAlloc
@ stub SnmpUtilOidAppend
@ stub SnmpUtilOidCmp
@ stub SnmpUtilOidCpy
@ stub SnmpUtilOidFree
@ stub SnmpUtilOidNCmp
@ stub SnmpUtilOidToA
@ stub SnmpUtilPrintAsnAny
@ stub SnmpUtilPrintOid
@ stub SnmpUtilStrlenW
@ stub SnmpUtilUnicodeToAnsi
@ stub SnmpUtilVarBindCpy
@ stub SnmpUtilVarBindFree
@ stub SnmpUtilVarBindListCpy
@ stub SnmpUtilVarBindListFree
