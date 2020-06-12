float4 main() : SV_TARGET
{
	return float4(1.0f, 1.0f, 1.0f, 1.0f);
}

/** The resterizer determines the pixel positions;
	the pixel shader just determines the colors of each of those pixels.
	It usually does not need the coordinate of a lixel in screen space
	in order to accomplish this task
*/