<CsoundSynthesizer>
<CsOptions>
-n
</CsOptions>
<CsInstruments>

sr = 44100
ksmps = 512
nchnls = 2
0dbfs = 1
/*
 //Possible channels to use: 
 //box 1 channels
chn_k "FaderA1", 3   // accepts values from 0 to 1
chn_k "FaderA2", 3	// accepts values from 0 to 1
chn_k "FaderA3", 3	// accepts values from -1 to 1
chn_k "FaderA4", 3	// accepts values from 0 to 1
chn_k "FaderA5", 3   // accepts values from -1 to 1
chn_k "CheckBox1", 3  // true/false values (1,0)
chn_k "CheckBox2", 3	 // true/false values (1,0)
chn_k "ComboBox1", 3	// int values from 0 to 4
 //box 2 channels
chn_k "FaderB1", 3   // accepts values from 0 to 1
chn_k "FaderB2", 3	// accepts values from 0 to 1
chn_k "FaderB3", 3	// accepts values from -1 to 1
chn_k "FaderB4", 3	// accepts values from 0 to 1
chn_k "FaderB5", 3   // accepts values from -1 to 1
chn_k "CheckBox3", 3  // true/false values (1,0)
chn_k "CheckBox4", 3	 // true/false values (1,0)
chn_k "ComboBox2", 3	// int values from 0 to 9
 //box 3 channels
chn_k "FaderC1", 3   // accepts values from 0 to 1
chn_k "FaderC2", 3	// accepts values from 0 to 1
chn_k "FaderC3", 3	// accepts values from -1 to 1
chn_k "FaderC4", 3	// accepts values from 0 to 1
chn_k "FaderC5", 3   // accepts values from -1 to 1
chn_k "CheckBox5", 3  // true/false values (1,0)
chn_k "CheckBox6", 3	 // true/false values (1,0)
chn_k "ComboBox3", 3	// int values from 0 to 14
 //box 4 channels
chn_k "FaderD1", 3   // accepts values from 0 to 1
chn_k "FaderD2", 3	// accepts values from 0 to 1
chn_k "FaderD3", 3	// accepts values from -1 to 1
chn_k "FaderD4", 3	// accepts values from 0 to 1
chn_k "FaderD5", 3   // accepts values from -1 to 1
chn_k "CheckBox7", 3  // true/false values (1,0)
chn_k "CheckBox8", 3	 // true/false values (1,0)
chn_k "ComboBox4", 3	// int values from 0 to 19
*/

gisine   ftgen 10, 0, 16384, 10, 1	;sine wave
giSawtooth ftgen 11,0, 2048, 10, 1, 0.5, 0.3, 0.25, 0.2 
gisaw    ftgen 12, 0, 16384, 10, 0, .2, 0, .4, 0, .6, 0, .8, 0,
1, 0, .8, 0, .6, 0, .4, 0,.2 
//giPulse   ftgen 52, 0, 128, 10, 1, 1, 1, 0.7, 0.5, 0.3, 0.1  
gisquare ftgen 13, 0, 16384, 10, 1, 0 , .33, 0, .2 , 0, .14, 0 , .11, 0, .09 ;odd harmonics
giPulse   ftgen 14, 0, 128, 10, 1, 1, 1, 0.7, 0.5, 0.3, 0.1  

instr 1
//just using a few of them
kamp chnget "FaderA1"
kfreq chnget "FaderA2"
kdistortEnable chnget "CheckBox1"
kdist chnget "FaderA3"
iwave chnget "ComboBox1"
iwave = iwave+10

kfreq = 10^(log10(20)+kfreq*(log10(20000)-log10(20))) // map the frequency range to 0-1 



a1 oscili 1, kfreq, iwave

if kdistortEnable == 1 then
a1 distort a1, kdist, -1
endif
outs a1*kamp, a1*kamp

endin



</CsInstruments>
<CsScore>
i1 0 z

</CsScore>
</CsoundSynthesizer>
<bsbPanel>
 <label>Widgets</label>
 <objectName/>
 <x>0</x>
 <y>0</y>
 <width>307</width>
 <height>326</height>
 <visible>true</visible>
 <uuid/>
 <bgcolor mode="background">
  <r>240</r>
  <g>240</g>
  <b>240</b>
 </bgcolor>
 <bsbObject type="BSBVSlider" version="2">
  <objectName>FaderA1</objectName>
  <x>34</x>
  <y>66</y>
  <width>20</width>
  <height>100</height>
  <uuid>{0adc11d4-f42c-4470-84b0-86d69bc5346c}</uuid>
  <visible>true</visible>
  <midichan>0</midichan>
  <midicc>0</midicc>
  <description/>
  <minimum>0.00000000</minimum>
  <maximum>1.00000000</maximum>
  <value>0.52000000</value>
  <mode>lin</mode>
  <mouseControl act="jump">continuous</mouseControl>
  <resolution>-1.00000000</resolution>
  <randomizable group="0">false</randomizable>
 </bsbObject>
 <bsbObject type="BSBVSlider" version="2">
  <objectName>FaderA2</objectName>
  <x>96</x>
  <y>63</y>
  <width>20</width>
  <height>100</height>
  <uuid>{8061181d-381e-4d0d-9e59-a034bd4bec31}</uuid>
  <visible>true</visible>
  <midichan>0</midichan>
  <midicc>0</midicc>
  <description/>
  <minimum>0.00000000</minimum>
  <maximum>1.00000000</maximum>
  <value>0.12000000</value>
  <mode>lin</mode>
  <mouseControl act="jump">continuous</mouseControl>
  <resolution>-1.00000000</resolution>
  <randomizable group="0">false</randomizable>
 </bsbObject>
 <bsbObject type="BSBVSlider" version="2">
  <objectName>FaderA3</objectName>
  <x>32</x>
  <y>226</y>
  <width>20</width>
  <height>100</height>
  <uuid>{77a032bd-0e1d-4aff-aa4f-329243c42c40}</uuid>
  <visible>true</visible>
  <midichan>0</midichan>
  <midicc>0</midicc>
  <description/>
  <minimum>0.00000000</minimum>
  <maximum>1.00000000</maximum>
  <value>0.00000000</value>
  <mode>lin</mode>
  <mouseControl act="jump">continuous</mouseControl>
  <resolution>-1.00000000</resolution>
  <randomizable group="0">false</randomizable>
 </bsbObject>
 <bsbObject type="BSBDropdown" version="2">
  <objectName>ComboBox1</objectName>
  <x>227</x>
  <y>281</y>
  <width>80</width>
  <height>30</height>
  <uuid>{61601c5a-3002-4e9b-b5af-53c3325c2ebf}</uuid>
  <visible>true</visible>
  <midichan>0</midichan>
  <midicc>0</midicc>
  <description/>
  <bsbDropdownItemList>
   <bsbDropdownItem>
    <name>item1</name>
    <value>0</value>
    <stringvalue/>
   </bsbDropdownItem>
   <bsbDropdownItem>
    <name>item2</name>
    <value>1</value>
    <stringvalue/>
   </bsbDropdownItem>
   <bsbDropdownItem>
    <name>item3</name>
    <value>2</value>
    <stringvalue/>
   </bsbDropdownItem>
  </bsbDropdownItemList>
  <selectedIndex>2</selectedIndex>
  <randomizable group="0">false</randomizable>
 </bsbObject>
 <bsbObject type="BSBCheckBox" version="2">
  <objectName>CheckBox1</objectName>
  <x>150</x>
  <y>188</y>
  <width>20</width>
  <height>20</height>
  <uuid>{5b474393-feee-465a-93bd-c0687ce99974}</uuid>
  <visible>true</visible>
  <midichan>0</midichan>
  <midicc>0</midicc>
  <description/>
  <selected>true</selected>
  <label/>
  <pressedValue>1</pressedValue>
  <randomizable group="0">false</randomizable>
 </bsbObject>
</bsbPanel>
<bsbPresets>
</bsbPresets>
