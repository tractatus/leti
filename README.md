## Install
```r
install.packages('ROpenCVLite')
ROpenCVLite::installOpenCV()
```

## Run
```r
library(leti)
filename<-system.file('INSTAseq_ch03.csv', package='leti')
points<-read.table(filename, sep=',', header=TRUE)
plot(points$x, points$y, pch=16, ylim=rev(range(points$y)), asp = 1, cex=0.5 )
rect()
```
Then run these dots on a TIFF:
```r
tiff.file<-system.file('INSTAseq_ch03.tif', package='leti')

intensity<-get.intensity(tiff.file, points$x, points$y, points$z)
```
