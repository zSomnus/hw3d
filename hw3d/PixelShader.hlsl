float4 main(float4 color : COLOR) : SV_TARGET
{
	return color;
}

/** The resterizer determines the pixel positions;
	the pixel shader just determines the colors of each of those pixels.
	It usually does not need the coordinate of a lixel in screen space
	in order to accomplish this task
*/