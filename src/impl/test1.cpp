/*
 * test1.cpp
 *
 *  Created on: Jul 1, 2015
 *      Author: thiagoh
 */

#include <string>
#include <map>
#include <boost/network/uri.hpp>
#include <boost/network/uri/uri_io.hpp>
#include <boost/network/protocol/http/client.hpp>

using namespace boost::network;
using namespace std;

int test1(char* uri) {

	uri::uri url(uri);

	/*<< Creates the client. >>*/
	http::client client;
	/*<< Creates a request using a URI supplied on the command line. >>*/
	http::client::request request(url);

	/*<< Gets a response from the HTTP server. >>*/
	http::client::response response = client.get(request);
	/*<< Prints the response body to the console. >>*/

	cout << "Request Body: " << body(response);
	cout << "Full url: " << url.string().c_str() << endl;
	cout << "Query 1: " << url.query().c_str() << endl;
	cout << "Query 2: " << url.query().c_str() << endl;

	std::map<std::string, std::string> queries;
	uri::query_map(url, queries);

	//cout << "Query size : " << queries.size() << endl;

	if (!queries.empty()) {

		std::map<std::string, std::string>::const_iterator itr(queries.begin());
		std::map<std::string, std::string>::const_iterator end(queries.end());

		for (; itr != end; ++itr) {
			cout << "Query : " << itr->first << " = " << itr->second << endl;
		}
	}

	//cout << "Query: " << url.query_range().

	cout << "\n\n" << endl;

	return 0;
}
