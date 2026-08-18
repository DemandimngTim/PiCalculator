#include "profile_loader.h"

#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

static bool get_bool(const unordered_map<string, string>& data,
                     const string& key,
                     bool default_value)
{
    auto it = data.find(key);

    if(it == data.end())
        return default_value;

    return it->second == "1" ||
           it->second == "true" ||
           it->second == "TRUE";
}

static int get_int(const unordered_map<string, string>& data,
                   const string& key,
                   int default_value)
{
    auto it = data.find(key);

    if(it == data.end())
        return default_value;

    try
    {
        return stoi(it->second);
    }
    catch(...)
    {
        return default_value;
    }
}

static string get_string(const unordered_map<string, string>& data,
                         const string& key,
                         const string& default_value)
{
    auto it = data.find(key);

    if(it == data.end())
        return default_value;

    return it->second;
}

bool load_profile(Profile &p, const string &path)
{
    ifstream in(path);

    if(!in)
        return false;

    unordered_map<string,string> data;

    string line;

    while(getline(in, line))
    {
        size_t pos = line.find('=');

        if(pos == string::npos)
            continue;

        string key = line.substr(0, pos);
        string value = line.substr(pos + 1);

        data[key] = value;
    }

    p.name             = get_string(data, "name", p.name);

    p.tree_depth       = get_int(data, "tree_depth", p.tree_depth);
    p.thread_mode      = get_string(data, "thread_mode", p.thread_mode);
    p.parallel         = get_bool(data, "parallel", p.parallel);

    p.save_output      = get_bool(data, "save_output", p.save_output);
    p.output_file      = get_string(data, "output_file", p.output_file);
    p.overwrite        = get_bool(data, "overwrite", p.overwrite);
    p.save_format      = get_string(data, "save_format", p.save_format);

    p.algorithm        = get_string(data, "algorithm", p.algorithm);
    p.precision_mode   = get_string(data, "precision_mode", p.precision_mode);

    p.verify_after     = get_bool(data, "verify_after", p.verify_after);
    p.verify_level     = get_int(data, "verify_level", p.verify_level);
    p.reference_source = get_string(data, "reference_source", p.reference_source);

    p.show_emojis      = get_bool(data, "show_emojis", p.show_emojis);
    p.color_output     = get_bool(data, "color_output", p.color_output);
    p.verbose          = get_bool(data, "verbose", p.verbose);

    return true;
}
