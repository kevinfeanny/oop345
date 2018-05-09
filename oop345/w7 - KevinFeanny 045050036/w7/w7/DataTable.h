#ifndef _Datatable_H_
#define _Datatable_H_


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
namespace w8 {
				template<class T>

				class DataTable {
					int wdth, count;
					vector<T> x, y;
				public:
					//constructor to get data from file
					DataTable(ifstream& in, int width, int count) :wdth(width), count(count) {
						string line;
						for (size_t i = 0; !in.eof(); i++) {
							getline(in, line);
							
							stringstream lin;
							lin.str(line);

							T XX, YY;

							lin >> XX >> YY;
							
							

							x.push_back(XX);
							
							y.push_back(YY);
							




						}


					}
					//calculate mean
					T mean() const {
						return accumulate(y.begin(), y.end(), 0.0) / y.size();
					}
					//calculate sigma
					T sigma() const {
						T meanVal = mean();
						T sum = 0.0;
						for (int i = 0; i < y.size(); i++) {
							sum += (y[i] - meanVal) * (y[i] - meanVal);
						}
						return sqrt(sum / (y.size() / 2));
					}
					//calculate median
					T median() const {
						vector<T> sorter = y;
						sort(sorter.begin(), sorter.end());
						return sorter[sorter.size() / 2];

					}
					//calculate slope and y intercept
					void regression(T& slope, T& y_int) const {
						T avgx = accumulate(x.begin(), x.end(), 0.0) / x.size();
						T avgy = mean();
						T numerator = 0.0, denominator = 0.0;

						for (int i = 0; i < y.size(); i++) {
							numerator += (x[i] - avgx) * (y[i] - avgy);
							denominator += (x[i] - avgx) * (x[i] - avgx);
						}
						slope = numerator / denominator;
						y_int = avgy - (slope * avgx);

					}
					//display results
					void display(ostream& os) const {
						os << setw(wdth) << "X" << setw(wdth) << "Y" << endl;
						for (int i = 0; i < x.size(); i++) {
							os << setw(wdth) << fixed << setprecision(count) << x[i]
								<< setw(wdth) << fixed << setprecision(count) << y[i] << endl;



						}
 

					}

				};
				//operator overload to display results
				template<class T>
				ostream& operator<<(ostream& os, const DataTable<T>& d) {

					d.display(os);
					return os;


				}






}














#endif // !_Datatable_H_

