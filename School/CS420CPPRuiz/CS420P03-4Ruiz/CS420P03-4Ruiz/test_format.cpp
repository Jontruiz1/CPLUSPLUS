/*
 *  Copyright 2012-2016 Robert Marmorstein
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "test_base.h"

#include <iostream>
#include <string>

using namespace std;

TestFormat::TestFormat(const string test_name) : TestBase(test_name)
{
	fs->format();
	for (int i=0; i < 4002*24; ++i) {
		if (fs->m_disk[i] != '*') {
			fail_out << "Byte " <<  i << " is not a * character." << endl;
			break;
		}
	}
}
