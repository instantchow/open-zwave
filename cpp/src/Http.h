//-----------------------------------------------------------------------------
//
//	Http.h
//
//	Simple HTTP Client Interface to download updated config files
//
//	Copyright (c) 2015 Justin Hammond <Justin@dynam.ac>
//
//	SOFTWARE NOTICE AND LICENSE
//
//	This file is part of OpenZWave.
//
//	OpenZWave is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as published
//	by the Free Software Foundation, either version 3 of the License,
//	or (at your option) any later version.
//
//	OpenZWave is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU Lesser General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with OpenZWave.  If not, see <http://www.gnu.org/licenses/>.
//
//-----------------------------------------------------------------------------

#ifndef _Http_H
#define _Http_H

#include "Defs.h"

namespace OpenZWave
{

/* This is a abstract class you can implement if you wish to override the built in HTTP Client
 * Code in OZW with your own code.
 *
 * The built in Code uses threads to download updated files to a temporary file
 * and then this class moves the files into the correct place.
 *
 */

class i_HttpClient {
public:
	i_HttpClient() {};
	virtual ~i_HttpClient() {};
	virtual bool StartDownload(string url) = 0;
};


/* this is OZW's implementation of a Http Client. It uses threads to download Config Files in the background.
 *
 */

class HttpClient : public i_HttpClient {
	public:
	HttpClient();
	~HttpClient();
	bool StartDownload(string url);
};



} /* namespace OpenZWave */



#endif
