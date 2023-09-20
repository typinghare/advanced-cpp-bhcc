# Bitwise Discussion

## Bitwise Applications

Bitwise operations are ubiquitous in programming. One prominent example is the user file permission system in Linux. In Linux, the permissions of a file can be represented by a three-digit octal value, reflecting the permissions for the file's owner, group, and other users. Each permission is associated with a specific numeric value:

* r (read): 4 = 100<sub>(2)</sub>
* w (write): 2 = 10<sub>(2)</sub>
* x (execute): 1

For instance, the octal value 5 = 101<sub>(2)</sub> signifies that the file is readable and executable, yet not writable. This binary representation is not only intuitive for interpretation but also efficient for storage, in contrast to storing three separate digits.

Do you know any other famous and simple applications like this? 

## Bitwise Operation in Programming (Deprecated, see #2)

Bitwise operations are frequently used in programming, especially in the realm of game development. While working on a small game, I encountered a challenge with regard to directional changes. I designed an enumeration named "Direction," encompassing "UP," "RIGHT," "DOWN," and "LEFT." Altering the direction of a game unit is a common requirement, such as involving a 90-degree clockwise rotation, which is straightforward to implement. However, when it comes to the "turnAround" function, I used four if statements to implement it. Can I simplify the "turnAround" function by applying bitwise operations?

## Bitwise Operation in Programming 2

[389. Find the Difference](https://leetcode.com/problems/find-the-difference/description/)

Imagine you have two vectors, 
