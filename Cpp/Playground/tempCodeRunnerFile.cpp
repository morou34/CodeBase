while (1)
    {
        if (*it + *jt < target && jt != sorted_nums.end())
        {
            std::cout << *it << " + " << *jt << " = " << *it + *jt << std::endl;
            jt = std::next(jt, 1);

            continue;
        }
        else if (*it + *jt == target)
        {
            std::cout << *it << " | " << *jt << std::endl;
            break;
        }
        else
        {
            jt = std::next(jt, 1);
            it = std::next(it, 1);
            std::cout << "\n____________\n";
            continue;
        }
    }