/*
 	Ray
    Copyright (C) 2011  Sébastien Boisvert

	http://DeNovoAssembler.SourceForge.Net/

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You have received a copy of the GNU General Public License
    along with this program (COPYING).  
	see <http://www.gnu.org/licenses/>

*/

#include <scaffolder/SummarizedLink.h>

SummarizedLink::SummarizedLink(uint64_t leftContig,char leftStrand,uint64_t rightContig,char rightStrand,int average,int count){
	m_leftContig=leftContig;
	m_leftStrand=leftStrand;
	m_rightContig=rightContig;
	m_rightStrand=rightStrand;
	m_average=average;
	m_count=count;
}

uint64_t SummarizedLink::getLeftContig(){
	return m_leftContig;
}

char SummarizedLink::getLeftStrand(){
	return m_leftStrand;
}

uint64_t SummarizedLink::getRightContig(){
	return m_rightContig;
}

char SummarizedLink::getRightStrand(){
	return m_rightStrand;
}

int SummarizedLink::getAverage(){
	return m_average;
}

int SummarizedLink::getCount(){
	return m_count;
}

void SummarizedLink::pack(uint64_t*buffer,int*position){
	buffer[(*position)++]=getLeftContig();
	buffer[(*position)++]=getLeftStrand();
	buffer[(*position)++]=getRightContig();
	buffer[(*position)++]=getRightStrand();
	buffer[(*position)++]=getAverage();
	buffer[(*position)++]=getCount();
}

void SummarizedLink::unpack(uint64_t*buffer,int*position){
	m_leftContig=buffer[(*position)++];
	m_leftStrand=buffer[(*position)++];
	m_rightContig=buffer[(*position)++];
	m_rightStrand=buffer[(*position)++];
	m_average=buffer[(*position)++];
	m_count=buffer[(*position)++];
}

SummarizedLink::SummarizedLink(){
}
