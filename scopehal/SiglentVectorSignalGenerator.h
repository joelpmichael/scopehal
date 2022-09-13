/***********************************************************************************************************************
*                                                                                                                      *
* libscopehal v0.1                                                                                                     *
*                                                                                                                      *
* Copyright (c) 2012-2022 Andrew D. Zonenberg and contributors                                                         *
* All rights reserved.                                                                                                 *
*                                                                                                                      *
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the     *
* following conditions are met:                                                                                        *
*                                                                                                                      *
*    * Redistributions of source code must retain the above copyright notice, this list of conditions, and the         *
*      following disclaimer.                                                                                           *
*                                                                                                                      *
*    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the       *
*      following disclaimer in the documentation and/or other materials provided with the distribution.                *
*                                                                                                                      *
*    * Neither the name of the author nor the names of any contributors may be used to endorse or promote products     *
*      derived from this software without specific prior written permission.                                           *
*                                                                                                                      *
* THIS SOFTWARE IS PROVIDED BY THE AUTHORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED   *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL *
* THE AUTHORS BE HELD LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES        *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR       *
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                                                                          *
*                                                                                                                      *
***********************************************************************************************************************/

#ifndef SiglentVectorSignalGenerator_h
#define SiglentVectorSignalGenerator_h

/**
	@brief Siglent vector signal generators

	Tested on SSG5000X-V series. May also support 3000X but not tested.
 */
class SiglentVectorSignalGenerator : public virtual SCPIRFSignalGenerator
{
public:
	SiglentVectorSignalGenerator(SCPITransport* transport);
	virtual ~SiglentVectorSignalGenerator();

	//Instrument
	virtual unsigned int GetInstrumentTypes();
	virtual std::string GetName();
	virtual std::string GetVendor();
	virtual std::string GetSerial();

	//Vector signal generator
	virtual int GetChannelCount();
	virtual std::string GetChannelName(int chan);
	virtual bool GetChannelOutputEnable(int chan);
	virtual void SetChannelOutputEnable(int chan, bool on);
	virtual float GetChannelOutputPower(int chan);
	virtual void SetChannelOutputPower(int chan, float power);
	virtual float GetChannelCenterFrequency(int chan);
	virtual void SetChannelCenterFrequency(int chan, float freq);
	virtual bool IsVectorModulationAvailable(int chan);

public:
	static std::string GetDriverNameInternal();
	VSG_INITPROC(SiglentVectorSignalGenerator)
};

#endif
