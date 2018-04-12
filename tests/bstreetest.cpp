#include <catch.hpp>
#include <sstream>

#include "bstree.hpp"

TEST_CASE("creating empty tree")
{
	Tree tree;
	REQUIRE( tree.empty() == true );
}
