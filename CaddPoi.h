/*
 * CaddPoi.h
 *
 *  Created on: Jan 20, 2016
 *      Author: Arsalan Khan
 */

#ifndef CADDPOI_H_
#define CADDPOI_H_


#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"
using namespace std;


// Testing of the function addPoi in CRoute class


class CaddPoi: public CppUnit::TestFixture
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

	// Connecting The route to Databases and checking the possible test cases
		void PoiDatabaseconnect()
			{

			m_route->connectToWpDatabase(&m_pWpDatabase);
			m_route->connectToPoiDatabase(&m_pPoiDatabase);
			m_route->addWaypoint("Amsterdam");
			m_route->addWaypoint("Darmstadt");


			//CPPUNIT_ASSERT(1==m_route->getRoute().size());


			    m_route->addPoi("Berlin","Amsterdam");  // We have to pass the waypoints also so that after waypoints, Pois will be added //


			    // Calling the getRoute function from CRoute class

				CPPUNIT_ASSERT(3==m_route->getRoute().size());



			}

	// Performing test operation to check whether the POIs are added into the route or not.

		void testaddPoi()
			{

			m_route->addWaypoint("Amsterdam");

			m_route->addWaypoint("Darmstadt");

			m_route->addWaypoint("Hochschule Darmstadt");

			m_route->addPoi("Berlin","Amsterdam");  // We have to pass the waypoints also so that after waypoints, Pois will be added //
			m_route->addPoi("Landesmuseum","Darmstadt");
			m_route->addPoi("Mensa HDA","Hochschule Darmsatdt");


			CPPUNIT_ASSERT(0==m_route->getRoute().size());




			}

		static CppUnit::TestSuite* suite()
			{
				CppUnit::TestSuite* suite = new CppUnit::TestSuite("Selection Tests");
				suite->addTest(new CppUnit::TestCaller<CaddPoi>("POI Database Connection Testing",
						&CaddPoi::PoiDatabaseconnect));

				suite->addTest(new CppUnit::TestCaller<CaddPoi>("Adding POIs in Database Testing",
						&CaddPoi::testaddPoi));






				return suite;

			}







};

#endif /* CADDPOI_H_ */
