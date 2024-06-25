/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the
"Apache License"); you may not use this file except in compliance with the
Apache License. You may obtain a copy of the Apache License at
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Copyright (c) 2024 Audiokinetic Inc.
*******************************************************************************/
#include "stdafx.h"
#include "Generic_UI_for_CsoundPlugin.h"
#include "../SoundEnginePlugin/Generic_UI_for_CsoundSourceFactory.h"



#ifndef FLT_MAX
#define FLT_MAX          3.402823466e+38F        // max value
#endif
Generic_UI_for_CsoundPlugin::Generic_UI_for_CsoundPlugin()
{
}

Generic_UI_for_CsoundPlugin::~Generic_UI_for_CsoundPlugin()
{
}
// Property names
//const char* const szFaderA1 = "FaderA1";

// Store current plugin settings into banks when asked to.
/* bool Generic_UI_for_CsoundPlugin::GetBankParameters(const GUID& in_guidPlatform, AK::Wwise::Plugin::DataWriter& in_dataWriter) const
{
//    in_dataWriter.WriteReal32(m_propertySet.GetReal32(in_guidPlatform, szFaderA1));
    return false;
}*/


  bool Generic_UI_for_CsoundPlugin::GetSourceDuration(double& out_dblMinDuration, double& out_dblMaxDuration) const
{/*
     double dblDuration = 0.;
    if (m_propertySet.PropertyHasRTPC(szSineDuration))
    {
        out_dblMinDuration = 0.0;
        out_dblMaxDuration = FLT_MAX;
        return false;
    }
    dblDuration = m_propertySet.GetReal32(m_host.GetCurrentPlatform(), szSineDuration);
    out_dblMinDuration = dblDuration;
    out_dblMaxDuration = dblDuration;
    return true;   */     //  I have to do this because it is a pure virtual function in the base class and needed to be overriden and then implemented...
    return false;
}



AK_DEFINE_PLUGIN_CONTAINER(Generic_UI_for_Csound);
AK_EXPORT_PLUGIN_CONTAINER(Generic_UI_for_Csound);
AK_ADD_PLUGIN_CLASS_TO_CONTAINER(Generic_UI_for_Csound, Generic_UI_for_CsoundPlugin, Generic_UI_for_CsoundSource);

DEFINE_PLUGIN_REGISTER_HOOK;
DEFINEDUMMYASSERTHOOK;
