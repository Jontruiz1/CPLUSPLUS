
	//private helper member function
	void insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m) {
		// check p to determine if the term list is empty
		//		number_of_terms and highest_degree will be 0
		//		simply add m to the term_list


		// if there are monomials in the list then iterate through the list
		//	to figure out where to insert the new monomial

		// 3 cases:
			// the degree of the monomial matches the degree of a monomial in the list
			//		add the coefficients
			//			if the coefficient goes to 0
			//				you need to handle this case
			//			otherwise update the coefficient for the monomial in the list

			// monomial gets added before another monomial in the term_list
			//		update number_of_terms and possibly highest_degree


			// monomial gets added to the end of the term list
			//		update number_of_terms

	}


