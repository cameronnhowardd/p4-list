#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(add) {
    List<int> testList;
    int x = 0;
    testList.push_back(x);
    ASSERT_TRUE(testList.size() == 1);
    cout << testList.front() << endl;

    ASSERT_TRUE(testList.front() == 0);
}

TEST(remove) {
    List<int> testList;
    int x = 0;
    testList.push_back(x);
    testList.pop_front();
    ASSERT_TRUE(testList.size() == 0)
}

TEST (addfront){
    List<int> testList;
    int x = 0;
    int a = 1;
    int b = 2;
    int c = 3;
    testList.push_back(x);
    testList.push_back(a);
    testList.push_back(b);
    testList.push_back(c);
    testList.pop_front();
    ASSERT_TRUE(testList.front() == 1);
}

TEST(removeback){
    List<int> testList;
    int x = 0;
    int a = 1;
    int b = 2;
    int c = 3;
    testList.push_front(x);
    testList.push_front(a);
    testList.push_front(b);
    testList.push_front(c);
    testList.pop_back();
    ASSERT_TRUE(testList.back() == 1);
}

TEST(clear){
    List<int> testList;
    int x = 0;
    int a = 1;
    int b = 2;
    int c = 3;
    testList.push_front(x);
    testList.push_front(a);
    testList.push_front(b);
    testList.push_front(c);
    testList.clear();
    ASSERT_TRUE(testList.size() == 0);
}



TEST(iterase){
    List<int> testList;
    int x = 0;
    int a = 1;
    int b = 2;
    int c = 3;
    testList.push_back(x);
    testList.push_back(a);
    testList.push_back(b);
    testList.push_back(c);
    List<int>::Iterator it = testList.begin();
    while (it != testList.end()){
        testList.erase(it);
        it = testList.begin();
    }
    ASSERT_TRUE(testList.size() == 0);
    
}

TEST(itinsert){
    List<int> testList;
    int x = 0;
    int a = 1;
    int b = 2;
    int c = 3;
    testList.push_back(x);
    testList.push_back(a);
    testList.push_back(b);
    testList.push_back(c);
    List<int>::Iterator it = testList.begin();
    testList.insert(it, 2);
    ASSERT_TRUE(testList.front() == 2);
    
}

TEST(itinsert2){
    List<int> testList;
    int x = 0;
    int a = 1;
    int b = 2;
    int c = 5;
    testList.push_back(x);
    testList.push_back(a);
    testList.push_back(b);
    testList.push_back(c);
    List<int>::Iterator it = testList.begin();
    for (int i = 0; i < 3; i++){
        ++it;
    }
    testList.insert(it, 2);
    ASSERT_TRUE((*--it) == 2);
    
}

TEST(copylist){
    List<int> testList;
    int x = 0;
    int a = 1;
    int b = 2;
    int c = 5;
    testList.push_back(x);
    testList.push_back(a);
    testList.push_back(b);
    testList.push_back(c);
    List<int> newList = testList;
    ASSERT_TRUE(testList.front() == newList.front());
}

TEST(copylist2){
    List<int> testList;
    int x = 0;
    int a = 1;
    int b = 2;
    int c = 5;
    testList.push_back(x);
    testList.push_back(a);
    testList.push_back(b);
    testList.push_back(c);
    List<int> newList = testList;
    newList.push_front(18);
    ASSERT_TRUE(testList.front() != newList.front());
}

TEST(add2){
    List<int> testList;
    int x = 0;
    testList.push_back(x);
    ASSERT_TRUE(testList.size() == 1);
    List<int> newList = testList;
    testList.push_front(4);
    ASSERT_TRUE(testList.size() != newList.size());
    ASSERT_TRUE(testList.front() != newList.front());
    ASSERT_TRUE(testList.back() == 0);
}

TEST(remove2){
    List<int> testList;
    int x = 0;
    testList.push_back(x);
    testList.pop_front();
    ASSERT_TRUE(testList.size() == 0);
    testList.push_back(4);
    testList.push_back(5);
    testList.push_back(6);
    testList.pop_back();
    ASSERT_TRUE (testList.back() == 5);
    testList.pop_front();
    ASSERT_TRUE(testList.front() == 5);
}

TEST(accessfirstlast){
    List<int> testList;
    for(int i = 0; i < 10; i++){
        testList.push_back(i);
    }
    ASSERT_TRUE(testList.front() == 0);
    ASSERT_TRUE(testList.back() == 9);
}

TEST(isempty){
    List<int> testList;
    ASSERT_TRUE(testList.empty());
    for(int i = 0; i < 10; i++){
        testList.push_back(i);
    }
    ASSERT_FALSE(testList.empty());
}

TEST(issize){
    List<int> testList;
    ASSERT_TRUE(testList.size() == 0);
    for(int i = 0; i < 10; i++){
        testList.push_back(i);
    }
    ASSERT_TRUE(testList.size() == 10);
    List<int> copyList = testList;
    ASSERT_TRUE(copyList.size() == 10);
    testList.pop_back();
    ASSERT_TRUE(copyList.size() == 10);
    ASSERT_TRUE(testList.size() == 9);
}

TEST(imadeacopy){
    List<int> testList;
    ASSERT_TRUE(testList.size() == 0);
    for(int i = 0; i < 10; i++){
        testList.push_back(i);
    }
    List<int>copyList(testList);
    ASSERT_TRUE(copyList.front() == testList.front());
    ASSERT_TRUE(copyList.back() == testList.back());
    testList.pop_back();
    copyList.pop_back();
    ASSERT_TRUE(copyList.front() == testList.front());
    ASSERT_TRUE(copyList.back() == testList.back());
    testList.pop_back();
    copyList.pop_front();
    ASSERT_FALSE(copyList.front() == testList.front());
    ASSERT_FALSE(copyList.back() == testList.back());
}

TEST(imadeassignmentcopy){
    List<int> testList;
    ASSERT_TRUE(testList.size() == 0);
    for(int i = 0; i < 10; i++){
        testList.push_back(i);
    }
    List<int> copyList = testList;
    ASSERT_TRUE(copyList.front() == testList.front());
    ASSERT_TRUE(copyList.back() == testList.back());
    testList.pop_back();
    copyList.pop_back();
    ASSERT_TRUE(copyList.front() == testList.front());
    ASSERT_TRUE(copyList.back() == testList.back());
    testList.pop_back();
    copyList.pop_front();
    ASSERT_FALSE(copyList.front() == testList.front());
    ASSERT_FALSE(copyList.back() == testList.back());

}
TEST(selfAssignmentref){ 
    List<int> testList;
    ASSERT_TRUE(testList.size() == 0);
    for(int i = 0; i < 10; i++){
        testList.push_back(i);
    }
    List<int> &refcopyList = testList;
    ASSERT_TRUE(refcopyList.front() == testList.front());
    ASSERT_TRUE(refcopyList.back() == testList.back());
    testList.pop_back();
    ASSERT_TRUE(refcopyList.back() == testList.back());
    testList.pop_front();
    ASSERT_TRUE(refcopyList.front() == testList.front());
    refcopyList.pop_front();
    ASSERT_TRUE(refcopyList.front() == testList.front())
}

TEST(traversinglistPLUS){
    List<int> testList;
    for(int i = 0; i < 10; i++){
        testList.push_back(i);
    }
    List<int>::Iterator traverse = testList.begin();
    for (int i = 0; i < 8; i++){
        ++traverse;
    }
    ASSERT_TRUE(*traverse == 8);

}

TEST(traversinglistMINUS){
    List<int> testList;
    for(int i = 0; i < 10; i++){
        testList.push_back(i);
    }
    List<int>::Iterator traverse1 = testList.begin();
    for (int i = 0; i < 10; i++){
        ++traverse1;
    }
    ASSERT_TRUE(traverse1 == testList.end());
    List<int>::Iterator traverse = testList.begin();
    for (int i = 0; i < 9; i++){
        ++traverse;
    }
    --traverse;
    cout << *traverse << endl;
    for (int i = 0; i < 6; i++){
        --traverse;
        cout << *traverse << endl;
    }
    ASSERT_TRUE(*traverse == 2);

}

TEST(traversinglistbyiterators){
List<int>testList;
for(int i = 0; i < 12; i++){
    testList.push_back(i);
}
List<int>::Iterator traverse2 = testList.begin();
List<int>testList1;
for(int i = 0; i < 10; i++){
    testList1.push_back(i);
}
List<int>::Iterator it = testList1.begin();
for (int i = 0; i < 5; i++){
    ++traverse2;
}
for(int i = 0; i < 5; i++){
    ++it;
}
ASSERT_TRUE(*it == *traverse2);
}



TEST(itinsert3){
    List<int> testList;
    for(int i = 0; i < 12; i++){
        testList.push_back(i);
    }
    
    List<int>::Iterator it = testList.begin();
    for (int i = 0; i < 4; i++){
        ++it;
    }
    testList.insert(it, 2);
    List<int>::Iterator it2 = testList.begin();
     for (int i = 0; i < 4; i++){
        ++it2;
    }
    ASSERT_TRUE(*it2 == 2);
    
}

TEST(iterase3){
    List<int> testList;
    for(int i = 0; i < 12; i++){
        testList.push_back(i);
    }
    List<int>::Iterator it = testList.begin();
    for (int i = 0; i < 4; i++){
        ++it;
    }
    testList.erase(it);
    List<int>::Iterator it2 = testList.begin();
     for (int i = 0; i < 4; i++){
        ++it2;
    }
    ASSERT_TRUE(*it2 == 5);
}

TEST(iteratorempty){
    List<int> testList;
    List<int>::Iterator it = testList.begin();
    ASSERT_TRUE(it == testList.end())
}

TEST(itinsertoneelement){
    List<int> testList;
    testList.push_back(1);
    List<int>::Iterator it = testList.begin();
    testList.insert(it, 2);
    ASSERT_TRUE(*it == 1);
    ASSERT_TRUE(testList.size() == 2);
    
}

TEST(iteraseonelement){
    List<int> testList;
    testList.push_back(1);
    List<int>::Iterator it = testList.begin();
    testList.erase(it);
    ASSERT_TRUE(testList.size() == 0);
}
TEST(emptylistassignment){
    List<int> testList;
    List<int> newList = testList;
    ASSERT_TRUE(newList.size() == 0);
    List<int>copyList(testList);
    ASSERT_TRUE(copyList.size() == 0);
}
TEST(itinsert4){
    List<int> testList;
    for(int i = 0; i < 12; i++){
        testList.push_back(i);
    }
    
    List<int>::Iterator it = testList.begin();
    for (int i = 0; i < 4; i++){
        ++it;
    }
    testList.insert(it, 2);
    it = testList.begin();
    for (int i = 0; i < 12; i++){
        ++it;
    }
    for (int i = 12; i > 0; i--){
        --it;
    }
    for (int i = 0; i < 4; i++){
        ++it;
    }
    ASSERT_TRUE(*it == 2);
    List<int>::Iterator it2 = testList.begin();
    for (int i = 0; i < 12; i++){
        ++it2;
    }
    for (int i = 12; i > 0; i--){
        --it2;
    }
    for (int i = 0; i < 4; i++){
        ++it2;
    }
    ASSERT_TRUE(*it2 == 2);
    
}
TEST(itinsert0element){
    List<int> testList;
    List<int>::Iterator it = testList.begin();
    testList.insert(it, 2);
    ASSERT_TRUE(testList.front()p5 == 2);
    ASSERT_TRUE(testList.size() == 1);
}

TEST(iterase0lement){
    List<int> testList;
    List<int>::Iterator it = testList.begin();
    testList.erase(it);
    ASSERT_TRUE(testList.size() == 0);
}




TEST_MAIN()
