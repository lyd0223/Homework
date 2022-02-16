#include <iostream>
#include <string>

class GameServerString
{
public:
    static void Replace(std::string& _Text, const std::string& _Prev, const std::string& _Next, int _Count = 1)
    {
        while (_Count != 0)
        {
            int TargetPivot = _Text.find(_Prev);
            if (TargetPivot == std::string::npos)
            {
                return;
            }
            _Text.replace(TargetPivot, _Prev.size(), _Next);

            _Count--;
        }
    }

    static void Insert(std::string& _Text, int _Index, const std::string& _InsertText)
    {
        if (_Text.size() < _Index)
            return;
        _Text.replace(_Index, 0, _InsertText);
    }

    static void ToUpper(std::string& _Text, bool _IsUpper = true)
    {
        for (int i = 0; i < _Text.size(); i++)
        {
            if (_IsUpper)
            {
                _Text[i] = std::toupper(_Text[i]);
            }
            else
            {
                _Text[i] = std::tolower(_Text[i]);
            }
        }

    }

    static void Remove(std::string& _Text, const std::string& _DeleteText)
    {
        while (1)
        {
            if (_Text.find(_DeleteText) == std::string::npos)
                return;
            _Text.erase(_Text.find(_DeleteText), _DeleteText.size());
        }
    }

    static void TrimRemove(std::string& _Text)
    {
        Remove(_Text, " ");
    }

};


int main()
{
    /*std::string str = "hello imimim seonghyun";
    GameServerString::Replace(str, "im", "ss");
    GameServerString::Insert(str, 10, "GOOD");
    GameServerString::ToUpper(str);
    std::cout << str << std::endl;
    GameServerString::Remove(str, "GOOD");
    std::cout << str << std::endl;

    GameServerString::Insert(str, str.size(), "끝끝");
    std::cout << str << std::endl;
    
    GameServerString::Insert(str, 0, "시작start123");
    std::cout << str << std::endl;

    GameServerString::Insert(str, 4, "하나둘셋");
    std::cout << str << std::endl;

    GameServerString::ToUpper(str);
    std::cout << str << std::endl;
    
    GameServerString::TrimRemove(str);
    std::cout << str << std::endl;

    GameServerString::ToUpper(str, false);
    std::cout << str << std::endl;

    GameServerString::Remove(str, "시작");
    std::cout << str << std::endl;

    GameServerString::Replace(str, "끝", "end", 100);
    std::cout << str << std::endl;*/

}
