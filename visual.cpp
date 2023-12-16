#include "visual.h"
#include "Vec.h"
#include "fields.h"
#include "object.h"

void tokenize(string const &str, const char delim, vector<string> &out)
{
    /*
      parser of string
    */
    stringstream ss(str);
 
    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

string fadeColor(string c1, string c2, double mix = 0) {
    /*
    creates gradient
    */
    vector<int> rgb1, rgb2;
    for (size_t i = 1; i < c1.length(); i += 2) {
        rgb1.push_back(stoi(c1.substr(i, 2), nullptr, 16));
    }
    for (size_t i = 1; i < c2.length(); i += 2) {
        rgb2.push_back(stoi(c2.substr(i, 2), nullptr, 16));
    }

    std::vector<int> rgb;
    for (size_t i = 0; i < rgb1.size(); i++) {
        int component = static_cast<int>((1 - mix) * rgb1[i] + mix * rgb2[i]);
        rgb.push_back(component);
    }
    stringstream ss;
    ss << "#";
    for (int value : rgb) {
        ss << setfill('0') << setw(2) << hex << value;
    }

    return ss.str();
}


tuple<int, int, int> convertColor(const string& colorCode) {
  /*
    converts color: string #RRGGBB to turple (red, green, blue)
  */
    string hexValue = colorCode.substr(1);
    string redHex = hexValue.substr(0, 2);
    string greenHex = hexValue.substr(2, 2);
    string blueHex = hexValue.substr(4, 2);

    int red = stoi(redHex, nullptr, 16);
    int green = stoi(greenHex, nullptr, 16);
    int blue = stoi(blueHex, nullptr, 1SHA6);

    return make_tuple(red, green, blue);
}

vector<vector<vector<int>>> coloring(const vector<vector<double>>& arr, double max_el, const string& c1, const string& c2) {
  /*
    colors array: 2-dimentional with intensivity to 3-dimentional with colors
  */
    vector<vector<vector<int>>> colored_arr(arr.size(), vector<vector<int>>(arr[0].size(), vector<int>(3, 0)));
    
    for (int x = 0; x < arr.size(); ++x) {
        for (int y = 0; y < arr[0].size(); ++y) {
            if (arr[x][y] != NAN && arr[x][y] <= max_el) {
                double mix = max_el != 0 ? static_cast<double>(arr[x][y]) / max_el : 0;
                string color1 = fadeColor(c1, c2, mix);
                int r = stoi(color1.substr(1, 2), nullptr, 16);
                int g = stoi(color1.substr(3, 2), nullptr, 16);
                int b = stoi(color1.substr(5, 2), nullptr, 16);
                
                colored_arr[x][y][0] = r;
                colored_arr[x][y][1] = g;
                colored_arr[x][y][2] = b;
            } else {
                colored_arr[x][y][0] = 0;
                colored_arr[x][y][1] = 0;
                colored_arr[x][y][2] = 0;
            }
        }
    }
    return colored_arr;
}


void display_scalar_field(const vector<vector<vector<int>>>& arr){
  /*
    displays scalar field
  */

  sf::RectangleShape rectangle(sf::Vector2f(1, 1));
    for (int i = 0; i < FIELD_WIDTH; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
          rectangle.setFillColor(sf::Color(arr[i][j][0], arr[i][j][1], arr[i][j][2]));
          rectangle.setPosition(2*null_x+length_of_bold+i, j);
          window.draw(rectangle);
        }
    }
    window.display();
}

vector<vector<vector<int>>> get_scalar_field_ff (){
  /*
    gets scalar field from file and colors it
  */
  double max_value = 0;
  string line;
 
  vector<vector<double>> strings;
  ifstream in(POTENTIAL_FIELD_FILE);
  if (in.is_open()) {
    while (getline(in, line))
      {
        vector<string> out;
        vector<double> string;
        tokenize(line, ' ', out);
        for (int i=0; i<FIELD_WIDTH; i++){
          string.push_back(stod(out[i]));
          if (stod(out[i]) > max_value) max_value = stod(out[i]);
        }
        strings.push_back(string);
        }
  }
  in.close();
  vector<vector<vector<int>>> col_arr = coloring(strings, max_value, c3, c4);
  return col_arr;
}

vector<Vec> get_vector_field_ff (vector<int> &body){
  /*
    get vector field from file
  */
  double max_value = 0;
  string line;
  vector<vector<double>> strings;
  std::ifstream in(VECTOR_FIELD_FILE);
  int j = 0;
  if (in.is_open()) {
    while (std::getline(in, line))
      {
        vector<std::string> out;
        vector<double> string;
        tokenize(line, ' ', out);
        for (int i=0; i<FIELD_WIDTH*2; i++){
          if (isnan(stod(out[i]))){
            body.push_back(i);
            body.push_back(j);
          }
          else{
            if (i%(shape_of_grid*2)==0) {
              string.push_back(stod(out[i]));
              string.push_back(stod(out[i+1]));
              double len = pow((string[i]*string[i] + string[i+1]*string[i+1]), 0.5);
              if (len > max_value) max_value = len;
            }
          }
        }
        strings.push_back(string);
        j+=1;
        }
  }
  in.close();

  std::vector<Vec> vectors;
  for (int i = 0; i < num_of_vec; i++) {
    for (int j = 0; j < num_of_vec; j++){
      double len_of_vec = pow((strings[i][2*j]*strings[i][2*j] + strings[i][2*j+1]*strings[i][2*j+1]), 0.5);
      double mix = len_of_vec/max_value;
      string s = fadeColor(c1, c2, mix);  
      std::tuple<int, int, int> colorTuple = convertColor(s);
      int red, green, blue;
      std::tie(red, green, blue) = colorTuple;
      sf::Color color(red, green, blue);
      double k = shape_of_grid/max_value;
      Vec vec(2*null_x+length_of_bold+shape_of_grid*i, shape_of_grid*j, strings[i][2*j]*k, strings[i][2*j+1]*k, color);
      vectors.push_back(vec);}
  }
  return vectors;
}

void display_vector_field (vector<Vec> & vectors, vector<int> &body){
  /*
    displays vector field
  */
  
  for (int i = 0; i < num_of_vec*num_of_vec; i++) {
    vectors[i].vec_draw(window);
  }
  sf::RectangleShape rectangle(sf::Vector2f(1, 1));
  for (int i = 0; i < body.size(); i += 2) {
    rectangle.setFillColor(sf::Color(255, 0, 0));
    rectangle.setPosition(2*null_x+length_of_bold+body[i], body[i+1]);
    window.draw(rectangle);
  }

}


void visualisation (vector<vector<double>> &scalar_field, bool is_scalar, vector<Object> &objects){
        get_potential_field(std::vector<std::vector<double >> &scalar_field, std::vector<Object > &objects);
        if (is_scalar){
            give_potential_field(std::vector<std::vector<double >>& scalar_field);
            vector<vector<vector<int>>> col_arr = get_scalar_field_ff();
            display_scalar_field(col_arr);
        }
        else {
            vector<vector<double>> vector_field(FIELD_HEIGHT, vector<double>(FIELD_WIDTH, 0));
            get_vector_field(std::vector<std::vector<double >>& vector_field, std::vector<std::vector<double >>& scalar_field);
            give_vector_field(std::vector<std::vector<double >>& vector_field);
            vector<int> body;
            vector<Vec> vectors = get_vector_field(body);
            display_vector_field (vectors, body);
        }
}
