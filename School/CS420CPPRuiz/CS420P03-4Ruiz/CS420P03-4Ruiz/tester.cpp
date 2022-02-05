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


int main()
{
	
	
	TestFormat* a = new TestFormat("test_format");
	TestCreate* b = new TestCreate("test_create");
	TestList* c = new TestList("test_list");
	TestDelete* d = new TestDelete("test_delete");
	TestRename* e = new TestRename("test_rename");
	TestCopy* f = new TestCopy("test_copy");
	TestOpen* g = new TestOpen("test_open");
	TestClose* h = new TestClose("test_close");
	TestRead* i = new TestRead("test_read");
	TestWrite* j = new TestWrite("test_write");
	TestSimpleList* k = new TestSimpleList("test_simple_list");

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
	delete h;
	delete i;
	delete j;
	delete k;
	




}
