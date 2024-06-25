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

#include "Generic_UI_for_CsoundSource.h"
#include "../Generic_UI_for_CsoundConfig.h"

#include <AK/AkWwiseSDKVersion.h>

#include <csound.hpp>
#include <vector>
#include "CsoundGenerator.h"

AK::IAkPlugin* CreateGeneric_UI_for_CsoundSource(AK::IAkPluginMemAlloc* in_pAllocator)
{
    return AK_PLUGIN_NEW(in_pAllocator, Generic_UI_for_CsoundSource());
}

AK::IAkPluginParam* CreateGeneric_UI_for_CsoundSourceParams(AK::IAkPluginMemAlloc* in_pAllocator)
{
    return AK_PLUGIN_NEW(in_pAllocator, Generic_UI_for_CsoundSourceParams());
}

AK_IMPLEMENT_PLUGIN_FACTORY(Generic_UI_for_CsoundSource, AkPluginTypeSource, Generic_UI_for_CsoundConfig::CompanyID, Generic_UI_for_CsoundConfig::PluginID)

Generic_UI_for_CsoundSource::Generic_UI_for_CsoundSource()
    : m_pParams(nullptr)
    , m_pAllocator(nullptr)
    , m_pContext(nullptr)
{
}

Generic_UI_for_CsoundSource::~Generic_UI_for_CsoundSource()
{
}
//3rd function
AKRESULT Generic_UI_for_CsoundSource::Init(AK::IAkPluginMemAlloc* in_pAllocator, AK::IAkSourcePluginContext* in_pContext, AK::IAkPluginParam* in_pParams, AkAudioFormat& in_rFormat)
{
    m_pParams = (Generic_UI_for_CsoundSourceParams*)in_pParams;
    m_pAllocator = in_pAllocator;
    m_pContext = in_pContext;

    m_durationHandler.Setup(m_pParams->RTPC.fDuration, 0/*in_pContext->GetNumLoops()*/, in_rFormat.uSampleRate);
    
    sampleRate = in_rFormat.uSampleRate / 2;     // why I have to do this? if not it sounds an octave below, victor
    in_rFormat.channelConfig.SetStandard(AK_SPEAKER_SETUP_STEREO); //  it changes the channelConfig to Stereo, its mono by default
  //  generator = new CsoundGenerator("D:/maynooth/tesis/Generic_UI_for_Csound/genericName.csd", sampleRate);  // with this every time you play the plugin it is creating a new generator 
   
    const char* wwiseRoot = std::getenv("WWISEROOT");
    if (wwiseRoot != nullptr) {
        std::string csdFilePath = std::string(wwiseRoot) + "/CsoundInWwise.csd";
        generator = new CsoundGenerator(csdFilePath.c_str(), sampleRate);
    }
    return AK_Success;
}

AKRESULT Generic_UI_for_CsoundSource::Term(AK::IAkPluginMemAlloc* in_pAllocator)
{
    delete generator; // im not sure about  why is called twice?  
    AK_PLUGIN_DELETE(in_pAllocator, this);
    return AK_Success;
}

AKRESULT Generic_UI_for_CsoundSource::Reset()
{
    return AK_Success;
}

AKRESULT Generic_UI_for_CsoundSource::GetPluginInfo(AkPluginInfo& out_rPluginInfo)
{
    out_rPluginInfo.eType = AkPluginTypeSource;
    out_rPluginInfo.bIsInPlace = true;
    out_rPluginInfo.uBuildVersion = AK_WWISESDK_VERSION_COMBINED;
    return AK_Success;
}

void Generic_UI_for_CsoundSource::Execute(AkAudioBuffer* out_pBuffer)
{
    
    m_durationHandler.ProduceBuffer(out_pBuffer);
    //here you can update your kChannels
    //BOX 1: 
    generator->setKChannel("FaderA1", m_pParams->RTPC.fFaderA1);
    generator->setKChannel("FaderA2", m_pParams->RTPC.fFaderA2);
    generator->setKChannel("FaderA3", m_pParams->RTPC.fFaderA3);
    generator->setKChannel("FaderA4", m_pParams->RTPC.fFaderA4);
    generator->setKChannel("FaderA5", m_pParams->RTPC.fFaderA5);
    generator->setKChannel("CheckBox1", m_pParams->NonRTPC.fCheckBox1);
    generator->setKChannel("CheckBox2", m_pParams->NonRTPC.fCheckBox2);
    generator->setKChannel("ComboBox1", m_pParams->NonRTPC.fComboBox1);
    //BOX 2:
    generator->setKChannel("FaderB1", m_pParams->RTPC.fFaderB1);
    generator->setKChannel("FaderB2", m_pParams->RTPC.fFaderB2);
    generator->setKChannel("FaderB3", m_pParams->RTPC.fFaderB3);
    generator->setKChannel("FaderB4", m_pParams->RTPC.fFaderB4);
    generator->setKChannel("FaderB5", m_pParams->RTPC.fFaderB5);
    generator->setKChannel("CheckBox3", m_pParams->NonRTPC.fCheckBox3);
    generator->setKChannel("CheckBox4", m_pParams->NonRTPC.fCheckBox4);
    generator->setKChannel("ComboBox2", m_pParams->NonRTPC.fComboBox2);
    //BOX 3:
    generator->setKChannel("FaderC1", m_pParams->RTPC.fFaderC1);
    generator->setKChannel("FaderC2", m_pParams->RTPC.fFaderC2);
    generator->setKChannel("FaderC3", m_pParams->RTPC.fFaderC3);
    generator->setKChannel("FaderC4", m_pParams->RTPC.fFaderC4);
    generator->setKChannel("FaderC5", m_pParams->RTPC.fFaderC5);
    generator->setKChannel("CheckBox5", m_pParams->NonRTPC.fCheckBox5);
    generator->setKChannel("CheckBox6", m_pParams->NonRTPC.fCheckBox6);
    generator->setKChannel("ComboBox3", m_pParams->NonRTPC.fComboBox3);
    //BOX 4:
    generator->setKChannel("FaderD1", m_pParams->RTPC.fFaderD1);
    generator->setKChannel("FaderD2", m_pParams->RTPC.fFaderD2);
    generator->setKChannel("FaderD3", m_pParams->RTPC.fFaderD3);
    generator->setKChannel("FaderD4", m_pParams->RTPC.fFaderD4);
    generator->setKChannel("FaderD5", m_pParams->RTPC.fFaderD5);
    generator->setKChannel("CheckBox7", m_pParams->NonRTPC.fCheckBox7);
    generator->setKChannel("CheckBox8", m_pParams->NonRTPC.fCheckBox8);
    generator->setKChannel("ComboBox4", m_pParams->NonRTPC.fComboBox4);


    const AkUInt32 uNumChannels = out_pBuffer->NumChannels();

    bufferSize = static_cast<unsigned int>(out_pBuffer->MaxFrames());
    bufferArray.resize(bufferSize);   // if I find how to acces to bufferSize outside execute() it will save a lot of memory? victor
    samples.resize(bufferSize);   // I need to optimize this
    samples = generator->execute(bufferArray);

    AkUInt16 uFramesProduced;

    AkReal32* AK_RESTRICT pBuf0 = (AkReal32 * AK_RESTRICT)out_pBuffer->GetChannel(0);
    for (uFramesProduced = 0; uFramesProduced < out_pBuffer->uValidFrames; uFramesProduced += 2)
    {

        // Generate output here
        pBuf0[uFramesProduced] = static_cast<float>(samples[uFramesProduced]);
    }
    AkReal32* AK_RESTRICT pBuf1 = (AkReal32 * AK_RESTRICT)out_pBuffer->GetChannel(1);
    for (uFramesProduced = 0; uFramesProduced < out_pBuffer->uValidFrames; uFramesProduced += 2)
    {

        // Generate output here
        pBuf1[uFramesProduced] = static_cast<float>(samples[uFramesProduced + 1]);
    }


}

AkReal32 Generic_UI_for_CsoundSource::GetDuration() const  //4th function
{
    return m_durationHandler.GetDuration() * 1000.0f;
}
