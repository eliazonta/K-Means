# K-Means clustering 

![Build](https://github.com/eliazonta/K-Means/actions/workflows/c-cpp.yml/badge.svg)

K-Means is a clustering algorithm that aims to partition *n* data points into *k* clusters

```shell
cmake CMakeLists.txt
```

```shell
make
```

### TODO LIST
- [x] ⚠️ **IMPORTANT** fix centroids problems and output data (found some algorithm bug 🥲)
- [x] code time / performances 
- [ ] convergence 
- [ ] more effective cluster init [resource](https://towardsdatascience.com/an-approach-for-choosing-number-of-clusters-for-k-means-c28e614ecb2c)
- [ ] parallel (CUDA, OpenMP) 👀