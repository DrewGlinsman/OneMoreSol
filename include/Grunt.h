/*
 * Grunt.h
 *
 *  Created on: Oct 14, 2018
 *      Author: jabowden
 */

#ifndef INCLUDE_GRUNT_H_
#define INCLUDE_GRUNT_H_

#include "KoratEmpire.h"

class Grunt: public KoratEmpire {
public:
	Grunt();
	virtual ~Grunt();

	void wasShot();
};

#endif /* INCLUDE_GRUNT_H_ */
