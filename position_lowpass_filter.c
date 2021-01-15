
typedef struct
{
    float x;
    float y;
    float theta;
}RobotPos;

float PositionLowPassFilter(RobotPos _new_position)
{
	float _angle_f0=0.1,_position_x_f0=0.1f,_position_y_f0=0.1f;
    RobotPos _result_position;
	static RobotPos _last_position={0.0f,0.0f,0.0f};
	
    if(_new_position.theta < -3.1415926f * 16 /18)
    {
        _new_position.theta += 2.0f * 3.1415926f;
    }
    if(_last_position.theta < -3.1415926f * 16 /18)
    {
        _last_position.theta += 2.0f * 3.1415926f;
    }
	
    _result_position.theta = _new_position.theta * _angle_f0 + _last_position.theta * (1.0f - _angle_f0);
    _result_position.x = _new_position.x * _position_x_f0 + _last_position.x *  * (1.0f - _position_x_f0);
    _result_position.y = _new_position.y * _position_y_f0 + _last_position.y *  * (1.0f - _position_y_f0);
    if(_result_position.theta > 3.1415926f) _result_position.theta -= 2.0f * 3.1415926f;
	
	_last_position = _result_position;
    return _result_position;
}


