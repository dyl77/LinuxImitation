//  TestCase.cpp
//  HashTable
//
//  Created by Zakaria Al-Qudah on 3/17/20.
//  Copyright © 2020 Zakaria Al-Qudah. All rights reserved.
//

#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../node.hpp"
#include "../filesystem.hpp"

TEST_CASE ("Node")
{
    Node * n = new Node("root",'d');
    REQUIRE (n->GetName() == "root");
    REQUIRE (n->GetType() == 'd');
    REQUIRE (n->GetParent() == nullptr);
    REQUIRE (n->GetChildren().size() == 0);

    Node * child = new Node ("child",'f');
    n->AddChild(child);
    REQUIRE (n->GetChild("child") == child);

    n->AddChild("second",'f');
    REQUIRE (n->GetChild("second")->GetType() == 'f'); 
   
    Node * parent = new Node ("parent", 'd');
    n->SetParent (parent);
    REQUIRE (n->GetParent () == parent);
      
    REQUIRE(n->GetChildren().size() == 2);
    n->RemoveChild("second");
    REQUIRE(n->GetChildren().size() == 1);
 
    delete n;
    delete child;
    delete parent;
    
}

TEST_CASE("Test creating a file system")
{
   FileSystem * fs = new FileSystem();
   REQUIRE (fs->pwd() == "/root");
   REQUIRE (fs->ls() == "");
   delete fs;
}

TEST_CASE ("Test touch and mkdir")
{
   FileSystem * fs = new FileSystem();
   REQUIRE (fs->touch("file1") == "file file1 created successfully");
   REQUIRE (fs->touch("file1") == "Error: file1 exists");
   REQUIRE (fs->touch("file2") == "file file2 created successfully");
   REQUIRE (fs->mkdir("dir1") == "directory dir1 created successfully");
   REQUIRE (fs->mkdir("dir1") == "Error: dir1 exists");
   REQUIRE (fs->touch("dir1") == "Error: dir1 exists");
   REQUIRE (fs->ls() == "f file1\nf file2\nd dir1\n");
   REQUIRE (fs->pwd() == "/root");
   delete fs;
}

TEST_CASE("Test changing directories")
{
   FileSystem * fs = new FileSystem();
   fs->mkdir("dir");
   REQUIRE (fs->cd("dir") == "/root/dir");
   REQUIRE (fs->pwd() == "/root/dir");
   REQUIRE (fs->ls() == "");
   REQUIRE (fs->cd("..") == "/root");
   REQUIRE (fs->pwd() == "/root");
   REQUIRE (fs->cd("..") == "can't change to directory ..");
   fs->touch("file");
   REQUIRE (fs->cd("file") == "file: is not a directory");
   REQUIRE (fs->cd("dir2") == "dir2: no such directory");
   fs->cd("dir");
   fs->mkdir("dir2");
   fs->mkdir("dir3");
   REQUIRE (fs->cd("dir2") == "/root/dir/dir2");
   REQUIRE (fs->ls() == "");
   REQUIRE (fs->cd("..") == "/root/dir");
   REQUIRE (fs->cd("dir3") == "/root/dir/dir3");
   delete fs;
}
/*
TEST_CASE("Test mv")
{
  FileSystem * fs = new FileSystem();
  fs->touch("file1");
  REQUIRE (fs->mv("file1", "file2") == "file/dir renamed successfully");
  REQUIRE (fs->ls() == "f file2\n");
  REQUIRE (fs->mv("file3", "file4") == "file not found");
  delete fs;
}

TEST_CASE("Test rm from empty dir")
{
  FileSystem * fs = new FileSystem();
  REQUIRE(fs->rm("file1") == "No such file or directory");
  delete fs;
}

TEST_CASE("Test rm child that has siblings")
{ 
  FileSystem * fs = new FileSystem();
  fs->mkdir("dir1"); //dir1 is child
  fs->touch("file1"); // file1 is sibling
  REQUIRE(fs->rm("dir1") == "dir1 removed successfully");
  REQUIRE(fs->ls() == "f file1\n");
  delete fs;
}

TEST_CASE("Test rm of a child dir with files and dirs inside")
{
  FileSystem * fs = new FileSystem();
  fs->mkdir("dir1");
  fs->touch("file1");
  fs->mkdir("dir2");
  fs->cd("dir2");
  REQUIRE(fs->pwd() == "/root/dir2");
  fs->mkdir("dir3"); //going a bit deeper, dir3 is a child
  fs->touch("file3");
  fs->cd("dir3");
  REQUIRE(fs->pwd() == "/root/dir2/dir3");
  fs->touch("file1");
  fs->touch("file2");
  fs->mkdir("dir1");
  fs->cd(".."); // dir3 has some files now. Let's delete it
  REQUIRE (fs->rm("dir3") == "dir3 removed successfully");
  REQUIRE (fs->ls() == "f file3\n");
  delete fs;
  
}
*/


// Add more test cases as needed

// Compile & run:
// make test
