Steps I (@timsnyder) took to get (@gpdowning)'s repo 'make versions' without blowing up in a http://c9.io container (using the C++ template).

* installed gtest following https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
  * apt-get install libgtest-dev
  ```bash
  #!/bin/bash
  cd /usr/src/gtest
  sudo cmake .
  sudo make
  sudo mv -v libg* /usr/lib/

  ```
* Installed LLVM following http://apt.llvm.org/
  * created /etc/apt/sources.list.d/llvm-trusty.list
  * added llvm signing key with:
      wget -O - http://apt.llvm.org/llvm-snapshot.gpg.key|sudo apt-key add -
  * installed them all with 
    ```
    apt-get install clang-3.8 clang-3.8-doc libclang-common-3.8-dev libclang-3.8-dev libclang1-3.8 libclang1-3.8-dbg libllvm-3.8-ocaml-dev libllvm3.8 libllvm3.8-dbg lldb-3.8 llvm-3.8 llvm-3.8-dev llvm-3.8-doc llvm-3.8-examples llvm-3.8-runtime clang-modernize-3.8 clang-format-3.8 python-clang-3.8 lldb-3.8-dev
    ```
    
    Actually... I didn't because there were package conflicts and installing all of those takes >800MB, using up quite a bit of our free 2GB.

    Errors while installing clang-3.8
    ```
        Setting up binfmt-support (2.1.4-1) ...
        mount: permission denied
        update-binfmts: warning: Couldn't mount the binfmt_misc filesystem on /proc/sys/fs/binfmt_misc.
        mount: permission denied
        update-binfmts: warning: Couldn't mount the binfmt_misc filesystem on /proc/sys/fs/binfmt_misc.
        mount: permission denied
        update-binfmts: warning: Couldn't mount the binfmt_misc filesystem on /proc/sys/fs/binfmt_misc.
        mount: permission denied
        update-binfmts: warning: Couldn't mount the binfmt_misc filesystem on /proc/sys/fs/binfmt_misc.
         * Enabling additional executable binary formats binfmt-support
        mount: permission denied
        update-binfmts: warning: Couldn't mount the binfmt_misc filesystem on /proc/sys/fs/binfmt_misc.
           ...done.
        Setting up libclang-common-3.8-dev (1:3.8-2ubuntu3~trusty4) ...
        Setting up clang-3.8 (1:3.8-2ubuntu3~trusty4) ...
        Processing triggers for ureadahead (0.100.0-16) ...
        Setting up llvm-3.8-runtime (1:3.8-2ubuntu3~trusty4) ...
        mount: permission denied
        update-binfmts: warning: Couldn't mount the binfmt_misc filesystem on /proc/sys/fs/binfmt_misc.
        Setting up llvm-3.8 (1:3.8-2ubuntu3~trusty4) ...
    ```
        
* apt-get install doxygen
* apt-get install clang-format-3.8