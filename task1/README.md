Big and Little Endianness are the two ways of how bytes can be stored in a computer, such as integers or floating-point numbers.
Since memory is organized in bytes, systems must decide in what order the bytes of a largee data type should be placed.
There are two main conventions: Big-Endian (BE) and Little-Endian (LE).

In the Most-Significant-Byte (MSB) order, which is called Big-Endian, the most important byte, or the MSB, is stored first at the lowest memory address. The MSB is the part of the number that carries the highest value, like the first digit in a large decimal number, while the LSB is the smallest part, like the last digit in that number. In the Least-Significant-Byte (LSB) order, which is called Little-Endian, the least important byte (LSB) is stored first at the lowest memory address. Let’s suppose we have a 32-bit architecture, where a number takes 4 bytes in memory. If the number is stored at memory addresses starting from 0x00 up to 0x03, then in Big-Endian the MSB would be stored at address 0x00 and the LSB at address 0x03. In Little-Endian, it would be the other way around: the LSB would be stored at address 0x00 and the MSB at address 0x03.

The difference between BE and LE is mainly how the system decides which part of the number should come first in memory. In Big-Endian, numbers are stored in a way that looks more natural to humans, because the largest part comes first, just like how we normally write numbers. In Little-Endian, the smallest part comes first. Little-Endian is very common in modern processors because it can make certain operations faster. This difference does not change the actual value of the number, but it affects how the number is read from memory and how systems with different endianness communicate with each other.




