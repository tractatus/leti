#include <Rcpp.h>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <vector>

/* apply operation to stack */
RcppExport SEXP getIntensity(SEXP input, SEXP x, SEXP y, SEXP z, SEXP verbose) {
  BEGIN_RCPP
  Rcpp::RNGScope __rngScope; //this and BEGIN_RCPP and END_RCPP is needed for wrappers such as Rcpp::as<int>

  Rcpp::CharacterVector fname(input);
  std::string ffname(fname[0]);
  Rcpp::IntegerVector xPos(x);
  Rcpp::IntegerVector yPos(y);
  Rcpp::IntegerVector zPos(z);

  std::vector<cv::Mat> multipageImage;

  if(verbose){Rcpp::Rcout << "Loading image:" << ffname << std::endl;}
    cv::imreadmulti(ffname, multipageImage, cv::IMREAD_ANYDEPTH);
  if(verbose){Rcpp::Rcout << "====== LOADING DONE ======" << std::endl;}

  std::vector<ushort> intensity;
  //loop through your coordinates
  for (int i = 0; i < xPos.size(); i++) {
    intensity.push_back(multipageImage[zPos[i]].at<ushort>(yPos[i], xPos[i]));
  }


  return Rcpp::List::create(
    //_["x"] = xPoint,
    //_["y"] = yPoint,
    Rcpp::_["intensity"] = intensity
  );

  /*
   END
   */
  END_RCPP
}
