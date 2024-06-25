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

#include "Generic_UI_for_CsoundSourceParams.h"

#include <AK/Tools/Common/AkBankReadHelpers.h>

Generic_UI_for_CsoundSourceParams::Generic_UI_for_CsoundSourceParams()
{
}

Generic_UI_for_CsoundSourceParams::~Generic_UI_for_CsoundSourceParams()
{
}

Generic_UI_for_CsoundSourceParams::Generic_UI_for_CsoundSourceParams(const Generic_UI_for_CsoundSourceParams& in_rParams)
{
    RTPC = in_rParams.RTPC;
    NonRTPC = in_rParams.NonRTPC;
    m_paramChangeHandler.SetAllParamChanges();
}

AK::IAkPluginParam* Generic_UI_for_CsoundSourceParams::Clone(AK::IAkPluginMemAlloc* in_pAllocator)
{
    return AK_PLUGIN_NEW(in_pAllocator, Generic_UI_for_CsoundSourceParams(*this));
}

AKRESULT Generic_UI_for_CsoundSourceParams::Init(AK::IAkPluginMemAlloc* in_pAllocator, const void* in_pParamsBlock, AkUInt32 in_ulBlockSize)
{
    if (in_ulBlockSize == 0)
    {
        // Initialize default parameters here
        RTPC.fDuration = 0.0f;

        RTPC.fFaderA1 = 1.0f;
        RTPC.fFaderA2 = 0.0f;
        RTPC.fFaderA3 = 0.0f;
        RTPC.fFaderA4 = 0.0f;
        RTPC.fFaderA5 = 0.0f;
        NonRTPC.fCheckBox1 = false;
        NonRTPC.fCheckBox2 = false;
        NonRTPC.fComboBox1 = 1;
        // BOX 2:
        RTPC.fFaderB1 = 1.0f;
        RTPC.fFaderB2 = 0.0f;
        RTPC.fFaderB3 = 0.0f;
        RTPC.fFaderB4 = 0.0f;
        RTPC.fFaderB5 = 0.0f;
        NonRTPC.fCheckBox3 = false;
        NonRTPC.fCheckBox4 = false;
        NonRTPC.fComboBox2 = 1;
        // BOX 3:
        RTPC.fFaderC1 = 1.0f;
        RTPC.fFaderC2 = 0.0f;
        RTPC.fFaderC3 = 0.0f;
        RTPC.fFaderC4 = 0.0f;
        RTPC.fFaderC5 = 0.0f;
        NonRTPC.fCheckBox5 = false;
        NonRTPC.fCheckBox6 = false;
        NonRTPC.fComboBox3 = 1;
        // BOX 4:
        RTPC.fFaderD1 = 1.0f;
        RTPC.fFaderD2 = 0.0f;
        RTPC.fFaderD3 = 0.0f;
        RTPC.fFaderD4 = 0.0f;
        RTPC.fFaderD5 = 0.0f;
        NonRTPC.fCheckBox7 = false;
        NonRTPC.fCheckBox8 = false;
        NonRTPC.fComboBox4 = 1;


        m_paramChangeHandler.SetAllParamChanges();
        return AK_Success;
    }

    return SetParamsBlock(in_pParamsBlock, in_ulBlockSize);
}

AKRESULT Generic_UI_for_CsoundSourceParams::Term(AK::IAkPluginMemAlloc* in_pAllocator)
{
    AK_PLUGIN_DELETE(in_pAllocator, this);
    return AK_Success;
}

AKRESULT Generic_UI_for_CsoundSourceParams::SetParamsBlock(const void* in_pParamsBlock, AkUInt32 in_ulBlockSize)
{
    AKRESULT eResult = AK_Success;
    AkUInt8* pParamsBlock = (AkUInt8*)in_pParamsBlock;

    // Read bank data here
    RTPC.fDuration = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderA1 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderA2 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderA3 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderA4 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderA5 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    NonRTPC.fCheckBox1 = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    NonRTPC.fCheckBox2 = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    NonRTPC.fComboBox1 = READBANKDATA(AkInt32, pParamsBlock, in_ulBlockSize);
    //BOX 2:
    RTPC.fFaderB1 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderB2 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderB3 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderB4 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderB5 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    NonRTPC.fCheckBox3 = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    NonRTPC.fCheckBox4 = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    NonRTPC.fComboBox2 = READBANKDATA(AkInt32, pParamsBlock, in_ulBlockSize);
    //BOX 3:
    RTPC.fFaderC1 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderC2 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderC3 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderC4 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderC5 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    NonRTPC.fCheckBox5 = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    NonRTPC.fCheckBox6 = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    NonRTPC.fComboBox3 = READBANKDATA(AkInt32, pParamsBlock, in_ulBlockSize);
    //BOX 4:
    RTPC.fFaderD1 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderD2 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderD3 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderD4 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFaderD5 = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    NonRTPC.fCheckBox7 = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    NonRTPC.fCheckBox8 = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    NonRTPC.fComboBox4 = READBANKDATA(AkInt32, pParamsBlock, in_ulBlockSize);


    CHECKBANKDATASIZE(in_ulBlockSize, eResult);
    m_paramChangeHandler.SetAllParamChanges();

    return eResult;
}

AKRESULT Generic_UI_for_CsoundSourceParams::SetParam(AkPluginParamID in_paramID, const void* in_pValue, AkUInt32 in_ulParamSize)
{
    AKRESULT eResult = AK_Success;

    // Handle parameter change here
    switch (in_paramID)
    {
    case PARAM_DURATION_ID:
        RTPC.fDuration = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_DURATION_ID);
        break;
    case PARAM_FADERA1_ID:
        RTPC.fFaderA1 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERA1_ID);
        break;
    case PARAM_FADERA2_ID:
        RTPC.fFaderA2 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERA2_ID);
        break;
    case PARAM_FADERA3_ID:
        RTPC.fFaderA3 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERA3_ID);
        break;
    case PARAM_FADERA4_ID:
        RTPC.fFaderA4 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERA4_ID);
        break;
    case PARAM_FADERA5_ID:
        RTPC.fFaderA5 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERA5_ID);
        break;
    case PARAM_CHECKBOX1_ID:
        NonRTPC.fCheckBox1 = *reinterpret_cast<const bool*>(in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_CHECKBOX1_ID);
        break;
    case PARAM_CHECKBOX2_ID:
        NonRTPC.fCheckBox2 = *reinterpret_cast<const bool*>(in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_CHECKBOX2_ID);
        break;
    case PARAM_COMBOBOX1_ID:
        NonRTPC.fComboBox1 = *((AkInt32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_COMBOBOX1_ID);
        // BOX 2:
    case PARAM_FADERB1_ID:
        RTPC.fFaderB1 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERB1_ID);
        break;
    case PARAM_FADERB2_ID:
        RTPC.fFaderB2 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERB2_ID);
        break;
    case PARAM_FADERB3_ID:
        RTPC.fFaderB3 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERB3_ID);
        break;
    case PARAM_FADERB4_ID:
        RTPC.fFaderB4 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERB4_ID);
        break;
    case PARAM_FADERB5_ID:
        RTPC.fFaderB5 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERB5_ID);
        break;
    case PARAM_CHECKBOX3_ID:
        NonRTPC.fCheckBox3 = *reinterpret_cast<const bool*>(in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_CHECKBOX3_ID);
        break;
    case PARAM_CHECKBOX4_ID:
        NonRTPC.fCheckBox4 = *reinterpret_cast<const bool*>(in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_CHECKBOX4_ID);
        break;
    case PARAM_COMBOBOX2_ID:
        NonRTPC.fComboBox2 = *((AkInt32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_COMBOBOX2_ID);
        // BOX 3:
    case PARAM_FADERC1_ID:
        RTPC.fFaderC1 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERC1_ID);
        break;
    case PARAM_FADERC2_ID:
        RTPC.fFaderC2 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERC2_ID);
        break;
    case PARAM_FADERC3_ID:
        RTPC.fFaderC3 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERC3_ID);
        break;
    case PARAM_FADERC4_ID:
        RTPC.fFaderC4 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERC4_ID);
        break;
    case PARAM_FADERC5_ID:
        RTPC.fFaderC5 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERC5_ID);
        break;
    case PARAM_CHECKBOX5_ID:
        NonRTPC.fCheckBox5 = *reinterpret_cast<const bool*>(in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_CHECKBOX5_ID);
        break;
    case PARAM_CHECKBOX6_ID:
        NonRTPC.fCheckBox6 = *reinterpret_cast<const bool*>(in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_CHECKBOX6_ID);
        break;
    case PARAM_COMBOBOX3_ID:
        NonRTPC.fComboBox3 = *((AkInt32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_COMBOBOX3_ID);
        // BOX 4:
    case PARAM_FADERD1_ID:
        RTPC.fFaderD1 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERD1_ID);
        break;
    case PARAM_FADERD2_ID:
        RTPC.fFaderD2 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERD2_ID);
        break;
    case PARAM_FADERD3_ID:
        RTPC.fFaderD3 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERD3_ID);
        break;
    case PARAM_FADERD4_ID:
        RTPC.fFaderD4 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERD4_ID);
        break;
    case PARAM_FADERD5_ID:
        RTPC.fFaderD5 = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FADERD5_ID);
        break;
    case PARAM_CHECKBOX7_ID:
        NonRTPC.fCheckBox7 = *reinterpret_cast<const bool*>(in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_CHECKBOX7_ID);
        break;
    case PARAM_CHECKBOX8_ID:
        NonRTPC.fCheckBox8 = *reinterpret_cast<const bool*>(in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_CHECKBOX8_ID);
        break;
    case PARAM_COMBOBOX4_ID:
        NonRTPC.fComboBox4 = *((AkInt32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_COMBOBOX4_ID);


    default:
        eResult = AK_InvalidParameter;
        break;
    }

    return eResult;
}
