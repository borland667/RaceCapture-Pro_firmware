#ifndef GPS_H_
#define GPS_H_

#include "dateTime.h"
#include "geopoint.h"

#include <stddef.h>

enum GpsSignalQuality {
   GPS_QUALITY_NO_FIX = 0,
   GPS_QUALITY_SPS = 1,
   GPS_QUALITY_DIFFERENTIAL = 2,
};

struct GpsSample {
   GeoPoint point;
   millis_t time;
   float speed;
};

/**
 * A simple Time and Location sample.
 */
typedef struct _TimeLoc {
	GeoPoint point;
	millis_t time;
} TimeLoc;

void gpsConfigChanged(void);

void initGPS();

int checksumValid(const char *gpsData, size_t len);

void processGPSData(char *gpsData, size_t len);

void resetGpsDistance();

float getGpsDistance();

void resetLapCount();

int getLapCount();

millis_t getLastLapTime();

millis_t getLastSectorTime();

int getSector();

int getLastSector();

int getAtStartFinish();

int getAtSector();

void setUTCTime(float UTCTime);

float getSecondsSinceMidnight();

void updateSecondsSinceMidnight(float secondsSinceMidnight);

double calculateSecondsSinceMidnight(const char * rawTime);

float getTimeDiff(float from, float to);

float getTimeSince(float t1);

float getLatitude();

float getLongitude();

void updatePosition(float latitude, float longitude);

void onLocationUpdated();

enum GpsSignalQuality getGPSQuality();

void setGPSQuality(int quality);

int getSatellitesUsedForPosition();

float getGPSSpeed();

void setGPSSpeed(float speed);

/**
 * Returns Date time information as provided by the GPS system.
 */
DateTime getLastFixDateTime();

/**
 * @return Milliseconds since Unix Epoch.
 */
millis_t getMillisSinceEpoch();

/**
 * This exists for backwards compatibility and will be deprecated in the future.  Use
 * #getLastFixDateTime() or #getMillisSinceEpoch() instead if possible.
 * @return the seconds since the first GPS fix.
 */
float getSecondsSinceFirstFix();

#endif /*GPS_H_*/
