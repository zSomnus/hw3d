cbuffer CBuf
{
	float4 face_colors[6];
};

float4 main(uint tid : SV_PRIMITIVEID) : SV_TARGET
{
	return face_colors[tid / 2];
}

/** The resterizer determines the pixel positions;
	the pixel shader just determines the colors of each of those pixels.
	It usually does not need the coordinate of a lixel in screen space
	in order to accomplish this task
*/