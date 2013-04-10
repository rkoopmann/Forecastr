//
//  Forecastr.h
//  Forecastr
//
//  Created by Rob Phillips on 4/3/13.
//  Copyright (c) 2013 Rob Phillips. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

// Unit types
extern NSString *const kFCUSUnits;
extern NSString *const kFCSIUnits;
extern NSString *const kFCUKUnits;

// Forecast names used for the data block hash keys
extern NSString *const kFCCurrentlyForecast;
extern NSString *const kFCMinutelyForecast;
extern NSString *const kFCHourlyForecast;
extern NSString *const kFCDailyForecast;

// Additional names used for the data block hash keys
extern NSString *const kFCAlerts;
extern NSString *const kFCFlags;
extern NSString *const kFCLatitude;
extern NSString *const kFCLongitude;
extern NSString *const kFCOffset;
extern NSString *const kFCTimezone;

// Names used for the data point hash keys
extern NSString *const kFCCloudCover;
extern NSString *const kFCCloudCoverError;
extern NSString *const kFCHumidity;
extern NSString *const kFCHumidityError;
extern NSString *const kFCIcon;
extern NSString *const kFCPrecipAccumulation;
extern NSString *const kFCPrecipIntensity;
extern NSString *const kFCPrecipProbability;
extern NSString *const kFCPrecipType;
extern NSString *const kFCPressure;
extern NSString *const kFCPressureError;
extern NSString *const kFCSummary;
extern NSString *const kFCSunriseTime;
extern NSString *const kFCSunsetTime;
extern NSString *const kFCTemperature;
extern NSString *const kFCTemperatureMax;
extern NSString *const kFCTemperatureMaxError;
extern NSString *const kFCTemperatureMaxTime;
extern NSString *const kFCTemperatureMin;
extern NSString *const kFCTemperatureMinError;
extern NSString *const kFCTemperatureMinTime;
extern NSString *const kFCTime;
extern NSString *const kFCVisibility;
extern NSString *const kFCVisibilityError;
extern NSString *const kFCWindBearing;
extern NSString *const kFCWindSpeed;
extern NSString *const kFCWindSpeedError;

// Names used for weather icons
extern NSString *const kFCIconClearDay;
extern NSString *const kFCIconClearNight;
extern NSString *const kFCIconRain;
extern NSString *const kFCIconSnow;
extern NSString *const kFCIconSleet;
extern NSString *const kFCIconWind;
extern NSString *const kFCIconFog;
extern NSString *const kFCIconCloudy;
extern NSString *const kFCIconPartlyCloudyDay;
extern NSString *const kFCIconPartlyCloudyNight;
extern NSString *const kFCIconHail;
extern NSString *const kFCIconThunderstorm;
extern NSString *const kFCIconTornado;
extern NSString *const kFCIconHurricane;

@interface Forecastr : NSObject

@property (nonatomic, strong) NSString *apiKey;
@property (nonatomic, strong) NSString *units;
@property (nonatomic, strong) NSString *callback;

/**
 * Initializes and returns a new Forecastr singleton object
 *
 * @return A new singleton object
 */

+ (id)sharedManager;

/**
 * Requests the forecast for the given location and optional time and/or exclusions
 *
 * @return The JSON response
 *
 * @param lat The latitude of the location.
 * @param long The longitude of the location.
 * @param time (Optional) The desired time of the forecast in UNIX GMT format
 * @param exclusions (Optional) An array which specifies which data blocks you would like left off the response
 * @param success A block object to be executed when the operation finishes successfully.
 * @param failure A block object to be executed when the operation finishes unsuccessfully.
 *
 * @discussion For many locations, it can be 60 years in the past to 10 years in the future.
 */

- (void)getForecastForLatitude:(double)lat
                     longitude:(double)lon
                          time:(NSNumber *)time
                    exclusions:(NSArray *)exclusions
                       success:(void (^)(id JSON))success
                       failure:(void (^)(NSError *error, id response))failure;

/**
 * Returns a description based on the precicipation intensity
 *
 * @param precipIntensity The precipIntensity for the acquired forecast data
 */
- (NSString *)descriptionForPrecipIntensity:(float)precipIntensity;

/**
 * Returns an image name based on the weather icon type
 *
 * @param iconDescription The description of the weather icon for the acquired forecast data
 */
- (NSString *)imageNameForWeatherIconType:(NSString *)iconDescription;

/**
 * Returns a string with the JSON error message, if given, or the appropriate localized description for the NSError object
 *
 * @param error The NSError object given in the failure block of the request
 * @param response The JSON or AFHTTPRequestOperation (for JSONP only) object given in the failure block of the request
 */
- (NSString *)messageForError:(NSError *)error withResponse:(id)response;

@end
