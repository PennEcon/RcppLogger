#ifndef RCPPLOGGER_H
#define RCPPLOGGER_H

namespace RcppLogger {

  enum e_verbosity { ALL, INFO, WARNINGS, QUIET };

  class log_message {
      public:
          inline log_message(const char *header, int importance, int level) {
              this->importance = importance;
              this->level = level;
              if (importance > level) {
                  Rcpp::Rcout << header;
              }
          }

          inline ~log_message() {
              if (importance > level) {
                  Rcpp::Rcout << "\n";
              }
          }

          template<typename T>
          inline log_message &operator<<(const T &t) {
              if (importance > level) {
                  Rcpp::Rcout << t;
              }
              return *this;
          }

      private:
          int importance, level;
  };

  class logger {
      public:
          inline log_message error() {
              return log_message("[ERROR] ", 3, verbosity);
          }

          inline log_message info() {
              return log_message("[INFO] ", 1, verbosity);
          }

          inline log_message warning() {
              return log_message("[WARNING] ", 2, verbosity);
          }

          inline void configure(e_verbosity verbosity) {
              this->verbosity = verbosity;
          }

      private:
          // 0: Everything
          // 1: Error + Warnings
          // 2: Errors
          // 3: Quiet
          e_verbosity verbosity;
  };

  logger l;

  inline logger &log() {
      return l;
  }

}

#endif
