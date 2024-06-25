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

#ifndef Generic_UI_for_CsoundSourceParams_H
#define Generic_UI_for_CsoundSourceParams_H

#include <AK/SoundEngine/Common/IAkPlugin.h>
#include <AK/Plugin/PluginServices/AkFXParameterChangeHandler.h>


// Add parameters IDs here, those IDs should map to the AudioEnginePropertyID
// attributes in the xml property definition.
static const AkPluginParamID PARAM_DURATION_ID = 0;
static const AkPluginParamID PARAM_FADERA1_ID = 1;
static const AkPluginParamID PARAM_FADERA2_ID = 2;
static const AkPluginParamID PARAM_FADERA3_ID = 3;
static const AkPluginParamID PARAM_FADERA4_ID = 4;
static const AkPluginParamID PARAM_FADERA5_ID = 5;
static const AkPluginParamID PARAM_CHECKBOX1_ID = 6;
static const AkPluginParamID PARAM_CHECKBOX2_ID = 7;
static const AkPluginParamID PARAM_COMBOBOX1_ID = 8;
//BOX 2 PARAMS
static const AkPluginParamID PARAM_FADERB1_ID = 9;
static const AkPluginParamID PARAM_FADERB2_ID = 10;
static const AkPluginParamID PARAM_FADERB3_ID = 11;
static const AkPluginParamID PARAM_FADERB4_ID = 12;
static const AkPluginParamID PARAM_FADERB5_ID = 13;
static const AkPluginParamID PARAM_CHECKBOX3_ID = 14;
static const AkPluginParamID PARAM_CHECKBOX4_ID = 15;
static const AkPluginParamID PARAM_COMBOBOX2_ID = 16;
//BOX 3 PARAMS
static const AkPluginParamID PARAM_FADERC1_ID = 17;
static const AkPluginParamID PARAM_FADERC2_ID = 18;
static const AkPluginParamID PARAM_FADERC3_ID = 19;
static const AkPluginParamID PARAM_FADERC4_ID = 20;
static const AkPluginParamID PARAM_FADERC5_ID = 21;
static const AkPluginParamID PARAM_CHECKBOX5_ID = 22;
static const AkPluginParamID PARAM_CHECKBOX6_ID = 23;
static const AkPluginParamID PARAM_COMBOBOX3_ID = 24;
//BOX 4 PARAMS
static const AkPluginParamID PARAM_FADERD1_ID = 25;
static const AkPluginParamID PARAM_FADERD2_ID = 26;
static const AkPluginParamID PARAM_FADERD3_ID = 27;
static const AkPluginParamID PARAM_FADERD4_ID = 28;
static const AkPluginParamID PARAM_FADERD5_ID = 29;
static const AkPluginParamID PARAM_CHECKBOX7_ID = 30;
static const AkPluginParamID PARAM_CHECKBOX8_ID = 31;
static const AkPluginParamID PARAM_COMBOBOX4_ID = 32;


static const AkUInt32 NUM_PARAMS = 33;

struct Generic_UI_for_CsoundRTPCParams
{
    AkReal32 fDuration;
    AkReal32 fFaderA1;
    AkReal32 fFaderA2;
    AkReal32 fFaderA3;
    AkReal32 fFaderA4;
    AkReal32 fFaderA5;
    //BOX 2:
    AkReal32 fFaderB1;
    AkReal32 fFaderB2;
    AkReal32 fFaderB3;
    AkReal32 fFaderB4;
    AkReal32 fFaderB5;
    //BOX 3:
    AkReal32 fFaderC1;
    AkReal32 fFaderC2;
    AkReal32 fFaderC3;
    AkReal32 fFaderC4;
    AkReal32 fFaderC5;
    //BOX 4:
    AkReal32 fFaderD1;
    AkReal32 fFaderD2;
    AkReal32 fFaderD3;
    AkReal32 fFaderD4;
    AkReal32 fFaderD5;
    

};

struct Generic_UI_for_CsoundNonRTPCParams
{
    bool fCheckBox1; 
    bool fCheckBox2;
    AkInt32 fComboBox1;
    //BOX 2:
    bool fCheckBox3;
    bool fCheckBox4;
    AkInt32 fComboBox2;
    //BOX 3:
    bool fCheckBox5;
    bool fCheckBox6;
    AkInt32 fComboBox3;
    //BOX 4:
    bool fCheckBox7;
    bool fCheckBox8;
    AkInt32 fComboBox4;
};

struct Generic_UI_for_CsoundSourceParams
    : public AK::IAkPluginParam
{
    Generic_UI_for_CsoundSourceParams();
    Generic_UI_for_CsoundSourceParams(const Generic_UI_for_CsoundSourceParams& in_rParams);

    ~Generic_UI_for_CsoundSourceParams();

    /// Create a duplicate of the parameter node instance in its current state.
    IAkPluginParam* Clone(AK::IAkPluginMemAlloc* in_pAllocator) override;

    /// Initialize the plug-in parameter node interface.
    /// Initializes the internal parameter structure to default values or with the provided parameter block if it is valid.
    AKRESULT Init(AK::IAkPluginMemAlloc* in_pAllocator, const void* in_pParamsBlock, AkUInt32 in_ulBlockSize) override;

    /// Called by the sound engine when a parameter node is terminated.
    AKRESULT Term(AK::IAkPluginMemAlloc* in_pAllocator) override;

    /// Set all plug-in parameters at once using a parameter block.
    AKRESULT SetParamsBlock(const void* in_pParamsBlock, AkUInt32 in_ulBlockSize) override;

    /// Update a single parameter at a time and perform the necessary actions on the parameter changes.
    AKRESULT SetParam(AkPluginParamID in_paramID, const void* in_pValue, AkUInt32 in_ulParamSize) override;

    AK::AkFXParameterChangeHandler<NUM_PARAMS> m_paramChangeHandler;

    Generic_UI_for_CsoundRTPCParams RTPC;
    Generic_UI_for_CsoundNonRTPCParams NonRTPC;
};

#endif // Generic_UI_for_CsoundSourceParams_H
