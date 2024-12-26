Abstract: 
This project is focused on the exploration and analysis of the operating system process API,
centering on the fork() function and its modern alternative, posix_spawn(). Drawing inspiration
from Baumann et al.'s 2019 work, "A fork() in a road," the project delves into the differences
between the mechanisms, functionalities, advantages, and disadvantages of fork() and
posix_spawn() in process creation code. It is motivated by existing research about the
performance, efficiency, and security issues that fork() poses to operating systems.
posix_spawn() is proposed as an alternative to fork(). This project aims to extend the proposed
posix_spawn() alternative of fork() to practical applications. Open-source software code that
involves process creation has been modified to leverage posix_spawn() for its performance,
security, and resource benefits over fork(). Through this practical code adaptation, posix_spawn()
is highlighted to have significant technical and functional implications and advantages for the
process API over fork().
