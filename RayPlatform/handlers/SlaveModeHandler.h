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

#ifndef _SlaveModeHandler_h
#define _SlaveModeHandler_h

#include <RayPlatform/core/slave_modes.h>
#include <RayPlatform/core/types.h>

#ifdef CONFIG_MINI_RANKS

#define SlaveModeHandlerReference SlaveModeHandler*

#define __CreateSlaveModeAdapter ____CreateSlaveModeAdapterImplementation
#define __DeclareSlaveModeAdapter ____CreateSlaveModeAdapterDeclaration

/* this is a macro to create the header code for an adapter */
#define ____CreateSlaveModeAdapterDeclaration(corePlugin,handle) \
class Adapter_ ## handle : public SlaveModeHandler{ \
	corePlugin *m_object; \
public: \
	void setObject(corePlugin *object); \
	void call(); \
};

/* this is a macro to create the cpp code for an adapter */
#define ____CreateSlaveModeAdapterImplementation(corePlugin,handle)\
void Adapter_ ## handle ::setObject( corePlugin *object){ \
	m_object=object; \
} \
 \
void Adapter_ ## handle ::call(){ \
	m_object->call_ ## handle(); \
}

/**
 * base class for handling slave modes 
 * \author Sébastien Boisvert
 * with help from Élénie Godzaridis for the design
 */
class SlaveModeHandler{

public:

	virtual void call() = 0;

	virtual ~SlaveModeHandler(){}
};

#else

/*
 * Without mini-ranks.
 */

#define __DeclareSlaveModeAdapter(corePlugin, handle)

/* this is a macro to create the cpp code for an adapter */
#define __CreateSlaveModeAdapter( corePlugin,handle ) \
void __GetAdapter( corePlugin, handle ) () { \
	__GetPlugin( corePlugin ) -> __GetMethod( handle ) () ; \
} 

/**
 * base class for handling slave modes 
 * \author Sébastien Boisvert
 * with help from Élénie Godzaridis for the design
 * \date 2012-08-08 replaced this with function pointers
 */
typedef void (*SlaveModeHandler) () /* */ ;

#define SlaveModeHandlerReference SlaveModeHandler

#endif

#define __ConfigureSlaveModeHandler(pluginName, handlerHandle) \
	handlerHandle= m_core->allocateSlaveModeHandle(m_plugin); \
	m_core->setSlaveModeObjectHandler(m_plugin, handlerHandle, \
		__GetAdapter(pluginName,handlerHandle)); \
	m_core->setSlaveModeSymbol(m_plugin, handlerHandle, # handlerHandle); \
	__BindAdapter(pluginName, handlerHandle);



#endif
