# Node hello world addon

This project's a simple node addons written in C++ using CMake.

To run it first type

    npm start

After execute this command you should see just a `Hello World!` message

This folder contains 2 main files:

main.js -> consumes the hello library using `require` keyword

main2.js -> consumes the hello library using `bidings` package

To run using the main2.js, type:

    npm run-script start2
