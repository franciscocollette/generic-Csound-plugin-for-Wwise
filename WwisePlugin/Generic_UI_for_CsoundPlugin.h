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

#pragma once

#include <AK/Wwise/Plugin.h>


class Generic_UI_for_CsoundPlugin final
    : public AK::Wwise::Plugin::AudioPlugin
    , public AK::Wwise::Plugin::RequestHost
    , public AK::Wwise::Plugin::Source
{
public:
    Generic_UI_for_CsoundPlugin();
    ~Generic_UI_for_CsoundPlugin();

    //virtual bool GetBankParameters(const GUID& in_guidPlatform, AK::Wwise::Plugin::DataWriter& in_dataWriter) const override;
    virtual bool GetSourceDuration(double& out_dblMinDuration, double& out_dblMaxDuration) const override; // is only needed to override the virtual function
};

AK_DECLARE_PLUGIN_CONTAINER(Generic_UI_for_Csound);  // name of the xml

/// See https://www.audiokinetic.com/library/edge/?source=SDK&id=plugin__dll.html
/// for the documentation about Authoring plug-ins
