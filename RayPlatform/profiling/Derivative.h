/*
 	RayPlatform: a message-passing development framework
    Copyright (C) 2010, 2011, 2012 Sébastien Boisvert

	http://github.com/sebhtml/RayPlatform

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You have received a copy of the GNU Lesser General Public License
    along with this program (lgpl-3.0.txt).  
	see <http://www.gnu.org/licenses/>

*/

#ifndef _Derivative_h
#define _Derivative_h

#include <RayPlatform/core/OperatingSystem.h>

#include <vector>
#include <fstream>
#include <map>
#include <stdint.h>
using namespace std;

/**
 * this class stores the progress of a computation task.
 * When asked, it prints the estimated remaining time.
 */
class Derivative{
	map<int,vector<int> > m_data;

	vector<uint64_t> m_timeValues;
	vector<int> m_xValues;

public:
	Derivative();
	void addX(int x);
	int getLastSlope();
	void printStatus(const char*mode,int modeIdentifier);
	void printEstimatedTime(int n);
	void clear();

	void writeFile(ostream*f);
};

#endif

