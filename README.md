# K-Means clustering 

![Build](https://github.com/eliazonta/K-Means/actions/workflows/c-cpp.yml/badge.svg)

## General
K-means clustering is a method of vector quantization, originally from signal processing, that aims to partition *n* observations into *k* clusters in which each observation belongs to the cluster with the nearest mean (cluster centers or cluster centroid), serving as a prototype of the cluster. This results in a partitioning of the data space into Voronoi cells. k-means clustering minimizes within-cluster variances (squared Euclidean distances), but not regular Euclidean distances, which would be the more difficult Weber problem: the mean optimizes squared errors, whereas only the geometric median minimizes Euclidean distances. For instance, better Euclidean solutions can be found using k-medians and k-medoids.

The problem is computationally difficult *(NP-hard)*; however, efficient heuristic algorithms converge quickly to a local optimum. These are usually similar to the expectation-maximization algorithm for mixtures of Gaussian distributions via an iterative refinement approach employed by both k-means and Gaussian mixture modeling.

[credits - Wikipedia](https://en.wikipedia.org/wiki/K-means_clustering)

## Usage

```shell
make
```
```shell
./bin/K-Means <dataset path> <N epochs> <K clusters>
```
