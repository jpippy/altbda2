#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#pragma warning( disable : 4995 4996 ) // no depreciated warnings
#include "NetworkProvider.h"
#include "Dll.h"

//#include "ConfDialog.h"

#include <stdio.h>
#include <WinVer.h>

#define DEFAULT_MOD_8PSK BDA_MOD_8VSB
#define DEFAULT_DISEQC DISEQC_COMMITED

enum VENDOR_SPECIFIC { PURE_BDA, WIN7_BDA, TT_BDA, HAUP_BDA, CXT_BDA, TBS_BDA, TH_BDA, DW_BDA, TV_BDA, OMC_BDA };
enum S2_ROLLOFF { ROLLOFF_NOT_SET = -1, ROLLOFF_NOT_DEFINED = 0x0,
	ROLLOFF_20 = 0x1, ROLLOFF_25, ROLLOFF_35 };
enum S2_PILOT { PILOT_NOT_SET = -1, PILOT_NOT_DEFINED = 0x0,
	PILOT_OFF = 0x1, PILOT_ON };

struct CONF_PARAMS
{
	char ConfVer[32];
	int ConfDiSEqC; 
	ModulationType ConfMod8PSK;
	int VendorSpecific;
	int S2RollOff;
	int S2Pilot;
};

class CConfiguration
{
public:
	CConfiguration();
	~CConfiguration();

	void Configure(HINSTANCE, int, char *);
	BOOLEAN ReadConfigurationFile();
	BOOLEAN CreateConfigurationFile();

	BOOLEAN DoConfigurationDialog();

	char DLLFilePath[256];
	BOOLEAN ConfigurationFileExists;
	struct CONF_PARAMS conf_params;

private:
//	CConfDialog *pConfDialog;
};

#endif /* CONFIGURATION_H */