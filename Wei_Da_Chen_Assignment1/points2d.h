/*
  Name: Wei Da Chen
  Date: 09/16/2021
	Header file: points2d.h
*/

/*
Points2D class describes a sequence of 2D points. For example (1, 3), (4, 5) is
a sequence of two points, where each coordinate is an integer. (1.2, 3.4),
(5.6, 10.1), (11.1, 12.0) is a sequence of three points where each coordinate is
a double.
*/

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
using namespace std;

namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2D {
private:
  // Sequence of points.
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  // Set size to 0.
  Points2D() {
    sequence_ = nullptr;
    size_ = 0;
  }

  // Copy-constructor - initializes an object using another object of the same class
  Points2D(const Points2D &rhs) {
    if (rhs.size_ == 0) {
      sequence_ = nullptr;
      size_ = 0;
    }

    size_ = rhs.size();
    sequence_ = new array<Object, 2>[rhs.size_];

    for (long unsigned i = 0; i < rhs.size_; i++) {
      sequence_[i] = rhs.sequence_[i];
    }
  }

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2D copy = rhs;
  // std::swap(*this, copy);
  // return *this;
  // }
  Points2D& operator=(const Points2D &rhs) {
    Points2D copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  // Move-constructor - allows the resources owned by an rvalue object to be moved into an lvalue without creating its copy
  Points2D(Points2D &&rhs) : sequence_(std::move(rhs.sequence_)), size_(std::move(rhs.size_)) {
    rhs.sequence_ = nullptr;
    rhs.size_ = 0;
  }

  // Move-assignment.
  // Just use std::swap() for all variables.
  Points2D& operator=(Points2D &&rhs) {
    if (this != &rhs) {
      swap(sequence_, rhs.sequence_);
      swap(size_, rhs.size_);
    }

    return *this;
  }

  ~Points2D() {
    delete[] sequence_;
    sequence_ = nullptr;
    size_ = 0;
  }

  // End of big-five.

  // One parameter constructor.
  Points2D(const std::array<Object, 2> &item) {
    size_ = 1;
    sequence_ = new array<Object, 2>[size_];
    sequence_[0] = item;
  }

  // Read a chain from standard input.
  void ReadPoints2D() {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line);
    std::stringstream input_stream(input_line);
    if (input_line.empty()) return;

    cout << endl;

    // Read size of sequence (an integer).
    int size_of_sequence;
    input_stream >> size_of_sequence;

    // Allocate space for sequence.
    // Add code here.
    size_ = size_of_sequence;
    sequence_ = new array<Object, 2>[size_of_sequence];

    Object token;
    for (int i = 0; input_stream >> token; ++i) {
      // Read coordinates.
      // Fill sequence_ here.
      sequence_[i][0] = token;
      input_stream >> token;
      sequence_[i][1] = token;
    }
  }

  size_t size() const {
    // Code missing.
    return size_;
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const {
    // Code missing.
    if (location < 0 || location > size_) {
      abort();
    }

    return sequence_[location];
  }

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
   // Code missing.
   Points2D valueSum;
   size_t smallSize;
   size_t largeSize;

   if (c1.size_ < c2.size_) {
     smallSize = c1.size_;
     largeSize = c2.size_;
     valueSum.sequence_ = new array<Object, 2>[c2.size_];
   }
   else if (c1.size_ > c2.size_) {
     smallSize = c2.size_;
     largeSize = c1.size_;
     valueSum.sequence_ = new array<Object, 2>[c1.size_];
   }

   valueSum.size_ = largeSize;

   for (unsigned i = 0; i < smallSize; i++) {
     valueSum.sequence_[i][0] =  c1.sequence_[i][0] + c2.sequence_[i][0];
     valueSum.sequence_[i][1] =  c1.sequence_[i][1] + c2.sequence_[i][1];
   }

   if (c1.size_ < c2.size_) {
     for (unsigned i = smallSize; i < largeSize; i++) {
       valueSum.sequence_[i][0] = c2.sequence_[i][0];
       valueSum.sequence_[i][1] = c2.sequence_[i][1];
     }
   }
   else if (c1.size_ > c2.size_) {
     for (unsigned i = smallSize; i < largeSize; i++) {
       valueSum.sequence_[i][0] = c1.sequence_[i][0];
       valueSum.sequence_[i][1] = c1.sequence_[i][1];
     }
   }

   return valueSum;
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points2) {
   // Code missing.
   if (some_points2.size_ == 0) {
     out << "()";
   }
   else {
     for (long unsigned i = 0; i < some_points2.size_; i++) {
       out << "(" << some_points2.sequence_[i][0] << ", " << some_points2.sequence_[i][1] << ") ";
     }
   }

   return out << endl;
 }
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2D_H_
