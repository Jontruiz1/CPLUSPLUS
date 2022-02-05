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
#include <iomanip>

TestBase::TestBase(const std::string test_name) : fail_out("Fail: "), m_test_name(test_name), fs(new FileSystem(test_name+".img",4194304)) {
}

TestBase::~TestBase() {
	std::string reason = fail_out.str();
	if (reason == "Fail: ")
		reason = "Pass";
	std::cout << std::setw(20) << m_test_name << " " << std::setw(60) << reason << std::endl;
	delete fs;
}
