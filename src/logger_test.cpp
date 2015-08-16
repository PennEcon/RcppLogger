#include <Rcpp.h>
#include "RcppLogger.h"

// [[Rcpp::plugins(cpp11)]]

using namespace Rcpp;

RcppLogger::logger logg(RcppLogger::ALL);

void log_something() {
  logg.info() << "Where's" << " the beef!?";
}

// [[Rcpp::export]]
void test_threads() {
  int N = 20;
  std::thread t[N];

  for (int i = 0; i < N; i++) {
    t[i] = std::thread(log_something);
  }

  for (int i = 0; i < N; i++) {
    t[i].join();
  }
}
