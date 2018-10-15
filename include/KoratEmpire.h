/*
 * KoratEmpire.h
 *
 *  Created on: Oct 14, 2018
 *      Author: jabowden
 */

#ifndef INCLUDE_KORATEMPIRE_H_
#define INCLUDE_KORATEMPIRE_H_

class KoratEmpire {
public:
	KoratEmpire();
	virtual ~KoratEmpire();
	float getHealth() const;
	void setHealth(float health);

private:
	float health;
};

#endif /* INCLUDE_KORATEMPIRE_H_ */
