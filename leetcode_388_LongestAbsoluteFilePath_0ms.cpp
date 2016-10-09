/**
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
**/

/**
注意事项：
    栈，当栈顶的文件深度比新读入的文件深度大或者等于时，就pop。
    注意使用.back()函数的时候记得检查容器是不是空了。
**/

class Solution {
public:

	struct stackitem {
		string name;
		int depth;
		bool flag;
	};
	int lengthLongestPath(string input) {
		vector<stackitem> stack;
		int ret = 0;
		while (0 != input.length())
		{
			stackitem item = readFileName(input);
			while (!stack.empty() && stack.back().depth >= item.depth)
			{
			    stack.pop_back();
			}
			stack.push_back(item);
			if (true == item.flag)//如果该item是一个文件
			{
				int total = sum(stack);
				ret = ret < total ? total : ret;
			}
		}
		return ret;
	}

	stackitem readFileName(string& input)
	{
		stackitem ret;
		int beg = 0, end = 0, realbeg = 0;
		int depth = 0;

		ret.flag = false;
		while (end < input.length() && input[end] != '\n')
		{
			if (input[end] == '.')
			{
				ret.flag = true;
			}
			end++;
		}//找到第一个文件名的结尾，并且判断是不是文件

		while (input[realbeg] == '\t')
		{
			realbeg++;
			depth++;
		}//找到文件名的真正开头并且计算出深度

		ret.name = input.substr(realbeg, end - realbeg);
		ret.depth = depth;
		if (end == input.length())
		{
			input = "";
		}
		else
		{
			input = input.substr(end + 1, input.length() - end - 1);//去掉开头的文件名
		}
		return ret;

	}

	int sum(vector<stackitem>& stack)
	{
		int ret = 0;
		for (auto itr = stack.begin(); itr != stack.end(); itr++)
		{
			ret += itr->name.size();
		}
		return ret + stack.size() - 1;
	}

};
