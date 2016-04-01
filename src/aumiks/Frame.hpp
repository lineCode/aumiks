#pragma once

#include <audout/AudioFormat.hpp>

#include <array>

#include <utki/debug.hpp>

namespace aumiks{

template <audout::Frame_e frame_type> struct Frame{
	std::array<std::int32_t, audout::AudioFormat::numChannels(frame_type)> channel;
	
	void add(const Frame& f){
		ASSERT(this->channel.size() == f.channel.size())
		for(unsigned i = 0; i != this->channel.size(); ++i){
			this->channel[i] += f.channel[i];
		}
	}
};

}
