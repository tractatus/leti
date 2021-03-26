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
```
Then run these dots on a TIFF:
```r
tiff.file<-system.file('INSTAseq_ch03.tif', package='leti')

out<-get.intensity(tiff.file, points$x, points$y, points$z)
log2int<-log2(out$intensity+1)
log2int<-log2int - min(log2int)

par(mfrow=c(1,2))
hist(log2int, main='', xlab='Intensity (log2)', col='black', breaks=100)
color<- colorRamp(c("darkblue", "white", "darkred"))
color<- rgb(color(log2int / max(log2int)), max=255)
plot(points$x, points$y, pch=16, ylim=rev(range(points$y)), asp = 1, cex=0.5, axes=F, ylab='', xlab='', col=color )

```
