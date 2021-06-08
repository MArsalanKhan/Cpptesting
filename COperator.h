/*
 * COperator.h
 *
 *  Created on: Jan 21, 2016
 *      Author: Arsalan Khan
 */

#ifndef COPERATOR_H_
#define COPERATOR_H_

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"
using namespace std;

class COperator: public CppUnit::TestFixture
{
private:
	CRoute* m_route;
	CPoiDatabase m_pPoiDatabase;
	CWpDatabase m_pWpDatabase;
public:
	void setUp()
				{
					m_route = new CRoute;

					CWaypoint WP_Amsterdam("Amsterdam",52.3731,4.8922);
					CWaypoint WP_Darmstadt("Darmstadt", 49.850, 8.6527);

					m_pWpDatabase.addWaypoint(WP_Amsterdam);
					m_pWpDatabase.addWaypoint(WP_Darmstadt);

					CPOI Berlin(SIGHTSEEING,"Berlin"," Berlin City Center ",52.51, 13.4);
					CPOI Landesmuseum(SIGHTSEEING,"Landesmuseum"," Best place to discover art ",49.854740, 8.643000);
					CPOI MensaHda(RESTAURANT,"Mensa HDA"," The best Mensa in the world ",49.866934, 8.637911);

						m_pPoiDatabase.addPoi(Berlin);
						m_pPoiDatabase.addPoi(Landesmuseum);
						m_pPoiDatabase.addPoi(MensaHda);



				}


			void tearDown()
				{
					delete m_route;
				}



			void testPluseq()
			    {

					m_route->operator +=("Amsterdam");
					CPPUNIT_ASSERT(0==m_route->getRoute().size());

					m_route->addWaypoint("Amsterdam");
					m_route->operator +=("Amsterdam");
					CPPUNIT_ASSERT(0==m_route->getRoute().size());


					//connection esthablished for the wp database
					m_route->connectToWpDatabase(&m_pWpDatabase);

					m_route->operator +=("Darmstadt");
					CPPUNIT_ASSERT(1==m_route->getRoute().size());

//					m_route->operator +=("Sweden");
//					CPPUNIT_ASSERT(1==m_route->getRoute().size());
//
//
					//connection esthablished for the POI database
					m_route->connectToPoiDatabase(&m_pPoiDatabase);

					m_route->operator +=("Berlin");
					CPPUNIT_ASSERT(1==m_route->getRoute().size());
//
//					m_route->operator +=("Landesmuseum");
//					CPPUNIT_ASSERT(2==m_route->getRoute().size());
//
//					m_route->operator +=("Mensa HDA");
//					CPPUNIT_ASSERT(4==m_route->getRoute().size());
//
//					m_route->addPoi("MENSA HDA","Amsterdam");
//					m_route->operator +=("MENSA HDA");
//					CPPUNIT_ASSERT(5==m_route->getRoute().size());

			    }


//			void eqtesting()
//				{
//					CRoute route1;
//					m_route->connectToWpDatabase(&m_pWpDatabase);
//
//
//					m_route->addWaypoint("Amsterdam");
//					m_route->operator =(route1);
//					CPPUNIT_ASSERT(0==route1.getRoute().size());
//
//					route1.connectToWpDatabase(&m_pWpDatabase);
//					m_route->operator =(route1);
//					CPPUNIT_ASSERT(1==route1.getRoute().size());
//
//					m_route->connectToPoiDatabase(&m_pPoiDatabase);
//
//					m_route->addPoi("MENSA HDA","Amsterdam");
//					m_route->operator =(route1);
//					CPPUNIT_ASSERT(1==route1.getRoute().size());
//
//					route1.connectToPoiDatabase(&m_pPoiDatabase);
//					m_route->operator =(route1);
//					CPPUNIT_ASSERT(2==route1.getRoute().size());
//
//				}
//
//
//			void addoperatorTest()
//				{
//					CRoute route1;
//					m_route->connectToWpDatabase(&m_pWpDatabase);
//					m_route->addWaypoint("Amsterdam");
//
//
//					m_route->operator +(route1);
//					CPPUNIT_ASSERT(0==route1.getRoute().size());
//
//					route1.connectToWpDatabase(&m_pWpDatabase);
//					route1.addWaypoint("Berlin");
//
//					m_route->operator +(route1);
//					CPPUNIT_ASSERT(1==route1.getRoute().size());
//
//					m_route->connectToPoiDatabase(&m_pPoiDatabase);
//					route1.connectToPoiDatabase(&m_pPoiDatabase);
//
//					m_route->operator +(route1);
//					route1.addPoi("MENSA HDA","Amsterdam");
//					CPPUNIT_ASSERT(2==m_route->getRoute().size());
//
//				}
//



          static CppUnit::TestSuite* suite()
						{
							CppUnit::TestSuite* suite = new CppUnit::TestSuite("Selection Tests");
							suite->addTest(new CppUnit::TestCaller<COperator>("Waypoint Database Connection Testing",
									&COperator::testPluseq));

//							suite->addTest(new CppUnit::TestCaller<COperator>("Adding Waypoint Database Testing",
//									&COperator::eqtesting));

//							suite->addTest(new CppUnit::TestCaller<COperator>("Adding Waypoint Database Testing",
	//															&COperator::addoperatorTest));




							return suite;

						}












};

#endif /* COPERATOR_H_ */
