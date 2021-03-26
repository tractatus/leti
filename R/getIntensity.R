#' Get intensity
#'
#' Get the intensity from pixel coordinates of a z-stack
#' @param input input a character vector consisting of the full path name to raw TIFF monochannel z-stack.
#' @param x pixel coordinates in x (0 is top left corner).
#' @param y pixel coordinates in y (0 is top left corner).
#' @param z pixel coordinates in z (0 is first plane)
#' @param verbose boolean value. If true diagnostic output is written to the R console. Deafult is true.
#' @examples
#' #path to image
#' image<-'/Volumes/microscope/animal001/slide001/section001.tif'
#' #get the intensity
#' intensity <- get.intensity(image, x, y, z)
get.intensity<-function(input, x, y, z, verbose=TRUE){
  file <- as.character(input)
  ## check for existence
  if(!file.exists(file))
    stop(file, ", file not found")
  file <- path.expand(file)


  intensities<-.Call("getIntensity", file, as.integer(x), as.integer(y), as.integer(z), as.integer(verbose))

  return(intensities)
}
